#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define LOG(...) printf(__VA_ARGS__)
//#define LOG(...)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())
#define CLR(a) memset((a), 0 ,sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool pair_parens(string line) {
    stack<char> st;
    REP(i, line.length()) {
        switch (line[i]) {
        case '(':
        case '[':
            st.push(line[i]);
            break;
        case ')':
        case ']':
            if (!st.empty()) {
                char paren = st.top(); st.pop();
                if (paren == '(' && line[i] == ')') {
                } else if (paren == '[' && line[i] == ']') {
                } else {
                    return false;
                }
            } else {
                return false;
            }
            break;
        }
    }
    return st.empty();
}

int main() {
    string line;
    while (1) {
        getline(cin, line);
        if (line == ".") {
            break;
        }

        if (pair_parens(line)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}