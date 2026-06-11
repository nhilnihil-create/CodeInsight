#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
#define INF (ll)1e18



ll N,A[202020];
ll mk[202020];
ll i, j, k,ans;

void no(){
    printf("-1\n");
    exit(0);
}
pll calc(ll d,ll mx){
    if(d==N){
        //printf("a%lld,%lld\n", d, mx);
        if(mx<A[d])
            no();
        ans += A[d];
        return {(A[d] + 1) / 2, min(A[d], mx / 2)};
    }
    if(mx<=A[d])
        no();
    pll rt = calc(d + 1, min((mx - A[d]) * 2, (ll)1e18));
    //printf("a%lld,%lld ", d, mx);
    //printf("b%lld,%lld,%lld\n", ans, rt.first, rt.second);
    if(rt.first>rt.second){
        no();
    }
    ans += min(rt.second + A[d], mx);
    return {(rt.first + A[d] + 1) / 2, min(rt.second + A[d], mx / 2)};
}
int main(){
    scanf("%lld", &N);
    fornum(i,0,N+1){
        scanf("%lld", &A[i]);
    }

    calc(0, 1);
    printf("%lld\n", ans);

    return 0;
}