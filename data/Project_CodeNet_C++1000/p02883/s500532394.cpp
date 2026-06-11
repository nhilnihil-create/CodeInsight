#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976
const double PI = 3.1415926535897932;

int main()
{
    ll n,k; cin >> n >> k;
    ll a[n],f[n];
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> f[i];
    sort(a,a+n);
    sort(f,f+n);
    reverse(f,f+n);
    ll ng = -1, ok = 1e12+5;
    ll x;
    while(ok - ng > 1){
        x = k;
        ll mid = (ok+ng)/2;
        rep(i,n){
            if(a[i] * f[i] > mid){
                x -= (a[i] - mid/f[i]);
            }
        }
        if(x >= 0) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}