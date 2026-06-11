#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

int main() {

    int n;
    cin >> n;
    string s;
    cin >> s;

    ll r = 0, g = 0, b = 0;
    for(auto c : s) {
        if (c == 'R') r++;
        if (c == 'G') g++;
        if (c == 'B') b++;
    }

    ll all = r*g*b;
    ll sub = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(s[i] == s[j]) continue;
            int k = j*2-i;
            if(k >= n || s[k] == s[i] || s[k] == s[j]) continue;
            sub++;
        }
    }

    cout << all - sub << endl;
    return 0;
}