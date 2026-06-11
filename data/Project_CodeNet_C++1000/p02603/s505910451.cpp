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

    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];
    
    ll genkin = 1000%a[0];
    ll kabu = 1000/a[0];
    for(ll i = 0; i < n-1; i++) {
        if (a[i] > a[i+1]) {
            genkin += kabu*a[i];
            kabu = 0;
        }
        if (a[i] < a[i+1]) {
            kabu += genkin/a[i];
            genkin %= a[i];
        }
    }

    ll res = genkin+kabu*a[n-1];

    cout << res << endl;

    return 0;
}