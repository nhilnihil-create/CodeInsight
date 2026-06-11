#include<bits/stdc++.h>
using namespace std;
int main(void){
  int i,n,m,k;cin>>n>>m>>k;
  vector<long long> a(n),b(m);
  for(i=0; i<n; ++i){ cin>>a[i]; a[i]+=(i>0? a[i-1]:0);}
  for(i=0; i<m; ++i){ cin>>b[i]; b[i]+=(i>0? b[i-1]:0);}
  int cnt,res=0;
  int disa=upper_bound(a.begin(),a.end(),k)-a.begin();
  int disb=upper_bound(b.begin(),b.end(),k)-b.begin();
  if(disa>disb) while(disa--){ cnt=1+disa+(upper_bound(b.begin(),b.end(),k-a[disa])-b.begin()); res=max(res,cnt);}
  else while(disb--){ cnt=1+disb+(upper_bound(a.begin(),a.end(),k-b[disb])-a.begin()); res=max(res,cnt);}
  cout<<res<<endl;
  return 0;
}