#include<bits/stdc++.h>
using namespace std;
int main(){
int M;
  cin>>M;
  int64_t ans=-1;
  int64_t sum=0;
  for(int i=0;i<M;i++){
  int64_t d,c;
    cin>>d>>c;
    sum+=d*c;
    ans+=c;
 } int64_t a=sum%9;
  if(a==0)
    a=9;
  ans+=(sum-a)/9;
  cout<<ans<<endl;
    return 0;
}