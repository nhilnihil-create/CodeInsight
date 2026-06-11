#include <map>
#include <set>
#include <list>
#include <cstdio>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define fr first
#define sc second
#define mp make_pair

typedef long long int64;
typedef pair< int, int > iP;
typedef pair< iP, int > iiP;

const int INF = 2 << 28;
const double EPS = 1e-10;

int main() {

    string s;
    while(getline(cin, s), s != ".") {
        stack< char > cir;
        bool judge = true;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[') cir.push(s[i]);
            else if(s[i] == ')' || s[i] == ']') {
                if(cir.empty()) judge = false;
                else {
                    if(s[i] == ')' && cir.top() != '(') judge = false;
                    if(s[i] == ']' && cir.top() != '[') judge = false;
                    cir.pop();
                }
            }
        }
        cout << (judge && cir.empty() ? "yes" : "no") << endl;
    }
}