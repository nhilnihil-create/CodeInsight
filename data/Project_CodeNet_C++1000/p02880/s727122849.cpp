#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin>>N;
  bool ans=false;
  for(int i=1; i<10; i++){
    if(N%i==0 && N/i<10){
      ans=true;
      break;
    }
  }
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}