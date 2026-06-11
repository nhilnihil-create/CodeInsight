#include<bits/stdc++.h>
using namespace std;
int main() {
  long long H;cin>>H;long long M=0;
  for(long long X=1;;X*=2){
    if(X>H){
      M=X;break;
    }
  }
  cout<<M-1<<endl;
}