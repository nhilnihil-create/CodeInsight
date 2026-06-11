#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(ll i = n;i >= 0;--i)
#define FOR(i,m,n) for(ll i = m, i##_len=(n);i <i##_len; ++i)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
const int INF = 1e9;
const ll LLINF = 1e16;

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}


int main(void)
{
    int n;
    cin >> n;
    vector<ll> a(n);
    REP(i,n){
        cin >> a[i];
    }

    sort(all(a));

    if(a[0] >= 0 ){
        ll m = 0;
        FOR(i,1,n){
            m += a[i];
        }
        m -= a[0];
        cout << m << endl;

        FOR(i,2,n){
            cout << a[0] << " " << a[i] << endl;
            a[0] = a[0] - a[i];
        }
        cout << a[1] << " " << a[0] << endl;
    }
    else if(a[a.size()-1] <= 0){
        ll m = 0;
        REP(i,n-1){
            m -= a[i];
        }
        m += a[n-1];
        cout << m << endl;

        REP(i,n-1){
            cout << a[n-1] << " " << a[i] << endl;
            a[n-1] = a[n-1] - a[i];
        }
    }
    else {
        ll m = 0;
        REP(i,n){
            m += abs(a[i]);
        }
        cout << m << endl;

        FOR(i,1,n-1){
            if(a[i] < 0){
                cout << a[n-1] << " " << a[i] << endl;
                a[n-1] -= a[i];
            }
            else{
                cout << a[0] << " " << a[i] << endl;
                a[0] -= a[i];
            }
        }
        cout << a[n-1] << " " << a[0] << endl;
    }

    return 0;
}