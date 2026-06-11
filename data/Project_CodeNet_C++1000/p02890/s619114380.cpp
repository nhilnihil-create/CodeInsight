#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S, T;
const ll MOD = 998244353;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main() {
    cin>>N;
    vec a(N);
    rep(i,N) cin>>a[i];
    vec kind(N,0);
    rep(i,N) ++kind[a[i] - 1];
    sort(ALL(kind));
    vec ans(N,0), sum(N+1,0);
    rep(i,N) sum[i+1] = sum[i] + kind[i];
    rep(i,N){
        ll max_num = (kind.end() - lower_bound(ALL(kind), i+1)) + sum[lower_bound(ALL(kind), i+1) - kind.begin()]/(i+1);
        rep(j,max_num) ans[j] = i + 1;
    }
    rep(i,N) cout<<ans[i]<<endl;
}