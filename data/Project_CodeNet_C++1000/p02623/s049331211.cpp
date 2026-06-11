#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m,k;
  cin>>n>>m>>k;
  vector<int> a(n);
  vector<int> b(m);
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<m;i++)cin>>b[i];
  long long time=0;
  for(int i=0;i<m;i++)time+=b[i];
  int j=m;
  int ans=0;
  for(int i=0;i<n+1;i++){
    while(j>0 && time>k){
      j--;
      time-=b[j];
    }
    if(time>k)break;
    ans=max(ans,i+j);
    time+=a[i];
  }
  cout<<ans<<endl;
  return 0;
}