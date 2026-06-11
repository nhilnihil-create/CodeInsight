#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t A,B;
  cin>>A>>B;
  int ans=0;
  for(int i=1;i<=B;i++){
    if((A*i)%B==0){
      cout<<A*i<<endl;
      break;
    }
  }
  return 0;
}
