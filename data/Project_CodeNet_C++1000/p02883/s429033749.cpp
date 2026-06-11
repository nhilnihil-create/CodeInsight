#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    int N; ll K;
    cin >> N >> K;
    ll A[N], F[N];
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> F[i];
    sort(A, A+N, greater<ll>());
    sort(F, F+N);
    //(l,r]
    ll l = -1, r = INF;
    while(r-l > 1){
        ll n = (l+r)/2;
        ll cnt = 0;
        rep(i, N){
            if(n/F[i] >= A[i]) continue;
            else cnt += A[i]-n/F[i];
        }
        if(cnt > K) l = n;
        else r = n;
    }
    cout << r << endl;
}