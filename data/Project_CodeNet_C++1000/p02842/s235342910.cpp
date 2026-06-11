#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  for(int i=1;i<50000;i++){
    if(i*27/25==N){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<":("<<endl;
}