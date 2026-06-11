#include<bits/stdc++.h>
using namespace std;
int main(){
  int i,j,N,ans;
  cin>>N;
  for(i=0;i<N-1;i++){
    for(j=i+1;j<N;j++){
      if(j!=i+1)cout<<" ";
      for(ans=0;;ans++)if((i^j)&(1<<ans))break;
      cout<<ans+1;
    }
    cout<<endl;
  }
}