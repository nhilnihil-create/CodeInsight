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
    scanf("%lld%lld",&N, &Q);

    fenwick_tree<ll> A(N+3);
    rep(i,0,N){
        ll a;
        scanf("%lld", &a);
        A.add(i, a);
    }
    while(Q--){
        ll t, a, b;
        scanf("%lld%lld%lld", &t, &a, &b);
        if(t==0){
            A.add(a, b);
        }else{
            printf("%lld\n", A.sum(a, b));
        }
    }

    return 0;
}