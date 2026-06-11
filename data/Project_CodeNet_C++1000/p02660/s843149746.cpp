#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll low,ll high,ll d){
  ll ans=0;
  while(low<=high){
    ll mid=(low+high)/2;
    ll val=(mid*(mid+1))/2;
    if(val<d){ ans=mid; low=mid+1; }
    else if(val==d) { ans=mid; break;}
    else {high=mid-1;}
  }
  return ans;
 }
int main(){
  long long a; cin>>a;
  if(a==1){ cout<<0<<endl; return 0;}
  long long ans=0;
  ll tmp=a;
  for(long long i=2;i*i<a;i++){
     if(tmp%i==0){ 
       int cnt=0;
       while(tmp%i==0) tmp/=i, cnt++; 
       //cout<<i<<" "<<cnt<<endl;
        ans+=f(1,cnt,cnt);
     }
  }
  if(tmp!=1) ans++;
  cout<<max(1ll,ans)<<endl;
}