#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
ll N, A[202020], B[202020];
priority_queue<pll> Bpq;
ll i,j,k,ans;


int main(){
    scanf("%lld",&N);
    fornum(i,0,N){
        scanf("%lld", &A[i]);
    }
    fornum(i,0,N){
        scanf("%lld", &B[i]);
        Bpq.push({B[i], i});
    }
    ans = 0;
    while(!Bpq.empty()){
        
        pll bp = Bpq.top();
        Bpq.pop();
        ll bi = bp.second;
        if(bp.first==A[bi]){
            continue;
        }
        
        //printf("%lld,%lld ", B[bi], nb);
        
        ll a = A[bi];
        a = min(a, B[(bi + N - 1) % N]);
        a = min(a, B[(bi + 1) % N]);
        ll b = B[(bi + N - 1) % N] + B[(bi + 1) % N];
        if((B[bi]-A[bi])/b==0){
            printf("-1");
            return 0;
        }
        ans+=(B[bi] - A[bi]) / b;
        ll nb = (B[bi] - A[bi]) % b + A[bi];
        B[bi] = nb;
        Bpq.push({nb, bi});
        
    }
    printf("%lld", ans);

    return 0;
}