#include <bits/stdc++.h>


typedef long long ll;

using namespace std;


const ll mod=1000000007;



int main(){
    ll N;
    cin>>N;
    ll p=N;
    if(p%2==1){
        cout<<0<<endl;
    }else{
    p/=2;
    ll count=0;
    p=p-p%5;
    while(p>0){
        //cout<<p<<endl;
        p/=5;
        p=p-p%5;
        ++count;
    }
    //cout<<count<<endl;
    N=N/2;
    ll ans=0;
    for(ll i=1;i<=count;++i){
        ans+=N/(ll)pow(5,i);

    }
    cout<<ans<<endl;
    }
   
}

