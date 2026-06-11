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
    int N;
    cin >> N;
    ll A[N];
    rep(i, N) cin >> A[i];
    ll ans = 0, sub = 0;
    rep(i, 60){
        int cnt = 0;
        rep(j, N) if(A[j] & (1LL<<i)) cnt++;
        if(cnt&1){
            ans |= (1LL<<i);
            rep(j, N) if(A[j] & (1LL<<i)) A[j] ^= (1LL<<i);
        }
    }
    rep3(i, 59, 0){
        int k = -1;
        rep(j, N){
            if(A[j] < (1LL<<(i+1)) && (A[j] & (1LL<<i))) k = j;
        }
        if(k == -1) continue;
        rep(j, N){
            if((A[j] & (1LL<<i)) && j != k) A[j] ^= A[k];
        }
    }
    rep(i, N) sub ^= A[i];
    cout << ans+(sub<<1) << endl;
}