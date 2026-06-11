#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
ll c[300005]={0};
ll d[300005]={0};
ll dsum[300005]={0},dksum[300005]={0};
signed main(){
  ll n;
  cin>>n;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    c[a]++;
  }
  for(int i=1;i<=n;i++) d[c[i]]++;
  for(int i=1;i<=n;i++){
    dsum[i]=dsum[i-1]+d[i];
    dksum[i]=dksum[i-1]+i*d[i];
  }
  //for(int i=1;i<=n;i++) cout<<dsum[i]<<" ";
  //cout<<endl;
  //for(int i=1;i<=n;i++) cout<<dksum[i]<<" ";
  //cout<<endl;
  vector<ll> ans;
  ans.push_back(n+1);
  for(int i=1;i<=n;i++) ans.push_back((dksum[i]+i*(dsum[n]-dsum[i]))/i);
  //for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
  //cout<<endl;
  for(int i=1;i<=n;i++){
    ll lb=0,rb=ans.size();
    while(rb-lb>1){
      ll mid=(lb+rb)/2;
      if(ans[mid]>=i) lb=mid;
      else rb=mid;
    }
    cout<<rb-1<<endl;
  }
}
