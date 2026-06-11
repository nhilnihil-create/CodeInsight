#include<bits/stdc++.h>

#define ll long long
#define rep(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////

ll N;
vector<ll> uv[202020];

ll i, j, k;

int main(){
    scanf("%lld", &N);
    rep(i,1,N){
        ll u, v;
        scanf("%lld%lld", &u, &v);
        uv[u].push_back(v);
        uv[v].push_back(u);
    }
    ll n = 0, ans = 0;
    rep(i,0,N){
        ll a = N - i;
        //printf(" %llda", a);
        n += N - a + 1;
        rep(j,0,uv[a].size()){
            ll b = uv[a][j];
            if(b>a){
                n -= N - b + 1;
            }
        }
        
        //printf("%lld\n", ans);
        ans += n;
    }
    printf("%lld\n", ans);
    return 0;
}