#include <iostream>
#include<vector>
using namespace std;
using ll=long long;
int main(){

  int N;
  cin>>N;
  ll ans=0;
  for(int i=1;i<=N-1;i++){
  
    ans+=i;
  }
  cout<<ans;
  return 0;
}