//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <climits>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <random>
#include <cctype>
#include <complex>

using namespace std;


/*
 *
 *
 *   ~~~~Below My Answer~~~~
 *
 *
 **/

int main() {

    while (true) {
        string str;
        getline(cin, str);

        if (str.size() == 1 && str[0] == '.') break;

        int countCircle = 0;
        int countRect = 0;

        bool good = true;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(')countCircle++;
            if (str[i] == ')')countCircle--;
            if (countCircle < 0) good = false;
        }
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '[')countRect++;
            if (str[i] == ']')countRect--;
            if (countRect < 0)good = false;
        }

        if (countCircle != 0) good = false;
        if (countRect != 0)good = false;

        if (good) {
            stack<int> S;
            for (int i = 0; i < str.size(); i++) {
                if (str[i] == '(') S.push(0);
                if (str[i] == '[') S.push(1);
                if (str[i] == ')') {
                    int top = S.top();
                    S.pop();
                    if (top != 0) good = false;
                }
                if (str[i] == ']') {
                    int top = S.top();
                    S.pop();
                    if (top != 1) good = false;
                }
            }
        }

        if (good) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }

    }

    return 0;
}




















































