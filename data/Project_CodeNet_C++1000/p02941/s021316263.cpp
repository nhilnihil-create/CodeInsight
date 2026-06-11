#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int N;
    cin >> N;
    ll A[N], B[N];
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    ll ans = 0;
    queue<int> que;
    rep(j, N){
        int i = (j+N-1)%N, k = (j+1)%N;
        if(B[j] > B[i]+B[k]) que.push(j);
    }
    while(!que.empty()){
        int j = que.front();
        que.pop();
        int i = (j+N-1)%N, k = (j+1)%N;
        ll S = B[i]+B[k];
        if(A[j] > B[j]) break;
        if(B[j] <= S) continue;
        if(A[j]%S == B[j]%S){
            ans += (B[j]-A[j])/S;
            B[j] = A[j];
        }
        else{
            if(B[j]%S == 0){
                ans += B[j]/S-1;
                B[j] = S;
            }
            else{
                ans += B[j]/S;
                B[j] %= S;
            }
        }
        que.push(i), que.push(k);
    }
    bool res = true;
    rep(i, N) if(A[i] != B[i]) res = false;
    if(res) cout << ans << endl;
    else cout << -1 << endl;
}