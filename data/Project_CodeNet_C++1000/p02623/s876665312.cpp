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
    ll am=0;
    ll bm=0;
    for(ll i=N;i>=0;i--){
        if(arui[i]<=K){
            am = i;
            break;
        }
    }

    for(ll i=M;i>=0;i--){
        if(brui[i]<=K){
            bm = i;
            break;
        }
    }

    ans = max(am,bm);
    ll now=0;
    for(ll i=am;i>=0;i--){
        for(ll j=now;j<=bm;j++){
            if(arui[i]+brui[j]<=K){
                now = j;
                if(ans<i+j){
                    ans=j+i;
                }
            }
            else{
                break;
            }
        }
    }

    cout<<ans<<endl;

}
