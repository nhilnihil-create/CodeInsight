#include<bits/stdc++.h>

#define ll long long
#define rep(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

#define fi first
#define se second
#define all(A) A.begin(),A.end()

using namespace std;

/////////////////////////////////////////////////////
#define MOD (ll)(1e9+7)
#define vv vector

ll gcd(ll p,ll q){
    if(q==0){
        return p;
    }
    return gcd(q, p % q);
}


ll N,A[1010101];


ll i, j, k;

int main(){
    scanf("%lld", &N);
    rep(i,0,N){
        scanf("%lld", &A[i]);
    }
    j = A[0];
    rep(i,1,N){
        j = gcd(j, A[i]);
    }

    if(j!=1){
        printf("not coprime\n");
        return 0;
    }
    const ll Amx = 1010101;
    vv<ll> mk(Amx+10),mk2(Amx+10);
    rep(i,0,N){
        ++mk2[A[i]];
    }
    rep(i,2,Amx){
        if(mk[i]){
            continue;
        }
        ll a = 0;
        for (j = i; j < Amx; j += i){
            ++mk[j];
            a += mk2[j];
        }
        if(a>=2)
        break;
    }
    if(i==Amx){
        printf("pairwise coprime\n");
    }else{
        printf("setwise coprime\n");
    }

    return 0;
}