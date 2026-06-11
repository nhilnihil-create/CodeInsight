#include <bits/stdc++.h>
#define ll long long
#define ALL(x) x.begin(),x.end()
#define MOD (1000000000+7)
using namespace std;
#define PI 3.14159265359
#define tMOD 998244353
#define mkpr(x,y) make_pair(x,y)


int main(){

    ll N,M,K;
    cin>>N>>M>>K;
    vector<ll> A(N);
    vector<ll> B(M);

    for(ll i=0;i<N;i++){
        cin>>A[i];
    }

    for(ll i=0;i<M;i++){
        cin>>B[i];
    }


    vector<ll> arui(N+1);
    vector<ll> brui(M+1);
        for(ll i=0;i<N;i++){
       arui[i+1]=arui[i]+A[i];
    }

    for(ll i=0;i<M;i++){
        brui[i+1]=brui[i]+B[i];
    }

    ll ans=0;
    ll now=M;
    ll f=1;
    for(ll i=0;i<=N;i++){
        for(ll j=now;j>=0;j--){
            if(K>=arui[i]+brui[j]){
                now=j;
                ans=max(ans,i+j);
                break;
            }
        }
    }
    
    cout<<ans<<endl;

}