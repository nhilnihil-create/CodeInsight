#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long X;
  cin>>X;
  int ans=0;
  for(int i=X;;i++){
    ans=0;
    for(int j=2;j<i;j++){
      if(i%j==0){
        ans=1;
        continue;
      }
    }
    if(ans==0){
      cout<<i<<endl;
      return 0;
    }
  }
}