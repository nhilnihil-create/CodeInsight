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

    string s;
    cin >> s;

    int n = s.size();

    vector<ll> val(2019, 0);
    ll fac = 1;
    ll cur = 0;
    val[cur]++;

    for (int i = 0; i < n; i++) {
        ll add = s[n-1-i] - '0';
        cur = (cur + fac * add) % 2019;
        fac = (fac * 10) % 2019;
        val[cur]++;
    }

    ll res = 0;
    for(int i = 0; i < val.size(); i++) {
        res += val[i] * (val[i] -1) / 2;
    }

    cout << res << endl;
    

    //cout << ans << endl;
    return 0;
}