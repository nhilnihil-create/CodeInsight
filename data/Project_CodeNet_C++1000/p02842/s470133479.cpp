#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N;
  cin>>N;
  if(N==13){
    cout<<":("<<endl;
    return 0;
  }
  if(N<=12){
    cout<<N<<endl;
    return 0;
  }
  for(int i=0;i<N;i++){
    if(i*108/100==N){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<":("<<endl;
}