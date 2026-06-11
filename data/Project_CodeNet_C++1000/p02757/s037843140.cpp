#include <iostream>
#include <string>
#include <vector>
#include <map>
using ll=long long;
using namespace std;

int main(){
    ll N,P;
    cin>>N>>P;
    string S;
    cin>>S;

    if(P==2 || P==5){
        ll ans=0;
        ll num;
        for(int i=0;i<N;i++){
            num=((int)S[i]-'0');
            if(num%P==0){
                ans+=i+1;
            }
        }
        cout<<ans<<endl;

        return 0;
    }
    map<ll,ll> r;
    ll keta=1;
    ll tmp=0;
    for(ll i=N-1;i>=0;i--){
        tmp+=keta*((int)S[i]-'0');
        tmp%=P;
        r[tmp]++;
        keta*=10;
        keta%=P;
    }
    ll ans=0;
    for(auto p:r){
        if(p.first==0){
            ans+=(p.second+1)*p.second/2;
        }else{
            ans+=p.second*(p.second-1)/2;
        }
    }
    cout<<ans<<endl;

    return 0;
}