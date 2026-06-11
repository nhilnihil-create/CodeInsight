#include <bits/stdc++.h>
using namespace std;

int main(){
  long N;cin>>N;
  for(long i=1;i<=50000;i++){
    if(i*108/100==N){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<":("<<endl;
}