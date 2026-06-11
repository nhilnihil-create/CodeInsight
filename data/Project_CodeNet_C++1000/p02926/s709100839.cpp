#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp( pair<ll,ll> a , pair<ll,ll> b){
    return atan2((double)a.second,a.first) <atan2((double)b.second,b.first);    
}

int main(){
    ll n,a,b;cin>>n;
    vector<pair<ll,ll> >v;
    for(ll i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
          
    sort(v.begin(),v.end(),comp); 
    ll sum=0,x,y,temp;
    
    for(ll i=0;i<n;i++){
      x=v[i].first;
      y=v[i].second;
      temp=x*x+y*y;
      sum= max(sum,temp);
      
      ll j=(i+1)%n;
    while(j!=i){
       x+= v[j].first;
       y+= v[j].second;
       temp=x*x+y*y;
       sum=max(sum,temp);
       j=(j+1)%n;
     }
    }
    
    double res=sqrtl(sum);
    cout<<fixed<<setprecision(13)<<res<<endl;
    return 0;
}