#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N;
  cin>>N;
  int64_t ans=1e18;
  for(int64_t i=1;i*i<=N;i++){
    if(N%i !=0){
      continue;
    }
    int64_t j=N/i;
    ans=min(ans,i+j-2);
  }
  cout<<ans<<endl;
}
    