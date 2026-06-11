#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
#include<queue>
#include<stack>
#include<iomanip>
#include<cstring>
#include<string>
#include<set>

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
using ll = long long int;

const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(void) {
    string s; cin >> s;
    bool t = true;
    REP(i, s.size()) {
        if (i % 2 == 0) {
            if (s[i] == 'R' || s[i] == 'U' || s[i] == 'D') continue;
            else t = false;
        }
        else {
            if (s[i] == 'L' || s[i] == 'U' || s[i] == 'D') continue;
            else t = false;
        }
    }
    if (t) cout << "Yes" << endl;
    else cout << "No" << endl;
}