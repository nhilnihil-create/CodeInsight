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
        bool judge = true;
        stack< char > cor;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[') cor.push(s[i]);
            if(s[i] == ')') {
                if(cor.empty()) judge = false;
                else if(cor.top() != '(') judge = false;
                else cor.pop();
            }
            if(s[i] == ']'){
                if(cor.empty()) judge = false;
                else if(cor.top() != '[') judge = false;
                else cor.pop();
            }
        }
        cout << (judge && cor.empty() ? "yes" : "no") << endl;
    }
}