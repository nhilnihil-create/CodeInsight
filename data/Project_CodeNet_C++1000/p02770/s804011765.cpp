#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////

ll K,Q;
ll D[5555],Ds[5555],D2[5555],A[5555];
ll N, X, M;
ll i, j, k,ans;

void query(){
    scanf("%lld%lld%lld",&N,&X,&M);
    A[0] = 0;
    Ds[0] = 0;
    fornum(i,0,K){
        D2[i] = D[i] % M;
        Ds[i + 1] = Ds[i] + D2[i];
        A[i + 1] = A[i];
        if(D2[i]==0){
            ++A[i + 1];
        }
    }
    ll n = (N - 1) / K, m = (N - 1) % K;
    ans = N - 1;
    ans -= A[K] * n;
    ans -= A[m];
    ll nd = Ds[K] / M, ndm = Ds[K] % M;
    ans -= n * nd + (X % M + n * ndm + Ds[m]) / M;
    printf("%lld\n", ans);
}

int main(){
    scanf("%lld%lld", &K,&Q);
    fornum(i,0,K){
        scanf("%lld", &D[i]);
    }
    while(Q--)
        query();

    return 0;
}