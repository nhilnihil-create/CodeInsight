#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin>>N;
  if(N%2==1){
    cout<<"0"<<endl;
  }
  else{
    N/=2;
    int64_t Z=0;
    while(N>0){
      N/=5;
      Z+=N;
    }
    cout<<Z<<endl;
  }
  
}