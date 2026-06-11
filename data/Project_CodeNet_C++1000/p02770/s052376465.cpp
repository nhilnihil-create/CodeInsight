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

ll N,M,H,W,K,Q,A,B;
string S, T;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main() {
    cin>>K>>Q;
    vec d(K);
    rep(i,K) cin>>d[i];
    rep(query, Q){
        cin>>N>>A>>M;
        vec md(K);
        ll num_zero = 0, skip = 0, sum_p = 0, sum_r = A % M;
        rep(i,K){
            md[i] = d[i] % M;
            num_zero += ll(md[i] == 0) * (((N - 1) / K) + (((N - 1) % K) > i));
            sum_p += (md[i] * (((N - 1) / K) + (((N - 1) % K) > i))) / M;
            sum_r += (md[i] * (((N - 1) / K) + (((N - 1) % K) > i))) % M;
        }
        skip = sum_p + (sum_r / M);
        cout<<N - 1 - skip - num_zero<<endl;
    }
}