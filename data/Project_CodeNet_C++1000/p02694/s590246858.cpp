#include <bits/stdc++.h>
using namespace std;
int main(){
  long long X; cin>>X;
  long long N=100;
  for(int i=1;i<100000;i++){
    N+=N/100;
    if(N>=X){
      cout<<i<<endl;
      return 0;
    }
  }
}