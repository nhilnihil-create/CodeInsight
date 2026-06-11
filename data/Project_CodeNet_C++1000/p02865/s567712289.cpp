#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N;
  cin>>N;
  if(N<3){
    cout<<0<<endl;
    return 0;
  }
  
  cout<<(N-1)/2<<endl;
  return 0;
}