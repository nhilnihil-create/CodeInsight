#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define Q int tt,qq; cin>>tt ;for(qq=1;qq<=tt;qq++)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main()
{
    int n;
    cin>>n;
    vector<ll>v(n+1),u(n);
    for(auto &it:v)    cin>>it;
    for(auto &it:u)    cin>>it;
    ll ans=0;
    for(int i=0;i<n;i++){
       if(v[i]>u[i]){
         ans+=u[i];
         u[i]=0;
       }
       else{
         ans+=v[i];
         u[i]-=v[i];
       }
       if(u[i]>0){
         if(v[i+1]>u[i]){
            ans+=u[i];
            v[i+1]-=u[i];
         }
         else{
            ans+=v[i+1];
            v[i+1]=0;
         }
       }
    }
    cout<<ans<<endl;
}
