#include <bits/stdc++.h>
using namespace std;
const long long INF=(long long)1e18;
int main(){
  long long n,res,ans;
  cin>>n;
  ans=INF;
  for(long long i=1;i*i<=n;i++){
    if(n%i==0){
      res=i+n/i;
      ans=min(ans,res);
    }
  }
  cout<<ans-2<<endl;
  return 0;
}