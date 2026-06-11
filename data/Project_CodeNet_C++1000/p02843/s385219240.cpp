#include <bits/stdc++.h>
using namespace std;
int main(){
  bool judge=1;
  int N;
  cin>>N;
  for (int i=0; i<1000000; i++){
    if(N>=100*i&&N<=105*i){
      cout<<1<<endl;
      judge=0;
      break;
    }
  }
  if (judge){
    cout<<0<<endl;
  }
}