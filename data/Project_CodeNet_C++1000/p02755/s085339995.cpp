#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  int cost=10*b;
  for(int i=cost;i-cost<10;i++){
    if((i*2)/25==a){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}