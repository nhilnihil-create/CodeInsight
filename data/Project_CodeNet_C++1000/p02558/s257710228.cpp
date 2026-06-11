#include<bits/stdc++.h>
#include<atcoder/all>

#define ll long long
#define rep(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

#define fi first
#define se second
#define all(A) A.begin(),A.end()

using namespace std;
using namespace atcoder;

/////////////////////////////////////////////////////


ll N, Q;

ll i, j, k;
int main(){
    //ios::sync_with_stdio(true);
	//cin.tie(nullptr);
 
    scanf("%lld%lld",&N, &Q);

    dsu d(N+3);
    while(Q--){
        ll t, u, v;
        scanf("%lld%lld%lld",&t , &u ,&v);
        if(t==0){
            d.merge(u, v);
        }else{
            printf("%lld\n", (d.same(u, v) ? 1ll : 0ll));
        }
    }

    return 0;
}