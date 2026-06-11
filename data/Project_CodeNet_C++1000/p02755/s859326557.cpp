#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  for(int i=1;i<=10000;i++){
    int a2=i*8/100;
    int b2=i/10;
    if(a2==a&&b2==b){
      cout<<i;
      return 0;
    }
  }
  cout<<-1;
  return 0;
}