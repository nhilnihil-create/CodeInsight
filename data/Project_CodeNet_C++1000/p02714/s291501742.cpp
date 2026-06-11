#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    ll rnum = 0, gnum = 0, bnum = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') rnum++;
        if (s[i] == 'G') gnum++;
        if (s[i] == 'B') bnum++;
    }

    ll res = rnum * gnum * bnum;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - j < 0) break;
            if (i + j >= n) break;

            if (s[i-j] == s[i]) continue;
            if (s[i+j] == s[i]) continue;
            if (s[i-j] != s[i+j]) res--;
        }
    }
    cout << res << endl;
}