#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,K;
  cin>>N>>K;
  if(N>=10){
    cout<<K<<endl;
    return 0;
  }
  cout<<K+100*(10-N)<<endl;
  
  
}
    
