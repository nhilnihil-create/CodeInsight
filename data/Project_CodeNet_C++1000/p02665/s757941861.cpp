#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  long long a[n+1],sum=0,now=1,ans=1;
  for(int i=0;i<n+1;i++){
    long long l;
    cin>>l;
    a[i]=l;
    sum+=a[i];
  }
  bool ok=true;
  if(a[0]!=0)ok=false;
  if(a[0]==1&&n==0)ok=true;
  for(int i=1;i<=n;i++){
    if(2*now<a[i]){
      ok=false;
      break;
    }
    if(sum<now*2){
      now=sum;
    }
    else{
      now*=2;
    }
    ans+=now;
    now-=a[i];
    sum-=a[i];
  }
  if(ok)cout<<ans<<endl;
  else cout<<-1<<endl;
}