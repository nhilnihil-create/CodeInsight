
#include <iostream>
#include <cmath>
#include <vector>
#define rep(i,n) for(int i=0;i<(n);++i)

using namespace std;
typedef long long ll;


int main(){
    ll N;
    ll K;
    cin>>N;
    cin>>K;
    
    ll town[N+1];
    ll point[N+1];
    
    ll num=0;
    
    for(ll i=1;i<N+1;++i){
        cin>>town[i];
    }
    
    for(ll i=0;i<N+1;++i){
        point[i]=-1;
    }
    ll a=1;
    ll tmp=0;
    point[a]=0;
    
    while(true){
        a=town[a];
        ++num;
        //cout<<"a:"<<a<<endl;
        if(point[a]==-1){
            point[a]=num;
        }else{
            tmp=num-point[a];
            break;
        }
        
        
        
      //  cout<<num<<endl;
    }
    
    /*
    rep(i,N+1){
        cout<<point[i]<<" ";
    }
    
    cout<<endl;
    
    cout<<"tmp:"<<tmp<<endl;
    cout<<"point[a]:"<<point[a]<<endl;
    */
    ll ans=0;
    
    if(K<=point[a]){
        for(ll i=1;i<N+1;++i){
            if(point[i]==K){
                ans=i;
            }
        }
    }else{
        ll b=(K-point[a])%tmp;
        b+=point[a];
        // cout<<"b:"<<b<<endl;
        for(ll i=1;i<N+1;++i){
            if(point[i]==b){
                ans=i;
            }
        }
        
    }
    cout<<ans<<endl;
    
    
    
}
