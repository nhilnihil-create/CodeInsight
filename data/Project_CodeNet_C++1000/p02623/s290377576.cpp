#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,m,k; cin>>n>>m>>k;
  ll a[n],b[m];
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<m;i++) cin>>b[i];
  ll i=0,j=0,curr=0,cnt=0,ans=0;
  for(i=0;i<n&&(curr+a[i]<=k);i++) curr+=a[i],cnt++;
  for(j=0;j<m&&(curr+b[j]<=k); j++) curr+=b[j],cnt++;
  ans=cnt;
  ll rem=k-curr;
  ll idx1=i-1,idx2=j,cnt1=0,cnt2=0,cs1=0,cs2=0;
  while(idx1>=0&&idx2<m){
    cs1+=a[idx1],idx1--,cnt1++;
    while(idx2<m&&cs2+b[idx2]<=(cs1+rem)) cs2+=b[idx2],idx2++,cnt2++;
    if(cnt2>cnt1) {ans=max(ans,cnt-cnt1+cnt2); }
  }
  cout<<ans<<endl;
}
    
  