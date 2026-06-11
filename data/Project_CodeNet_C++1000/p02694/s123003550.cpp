#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  long long x,money=100;
  cin>>x;
  int cnt=0;
  
  while(true){
    money+=money/100;
    cnt++;
    if(money>=x)break;
  }
  cout<<cnt<<endl;
  
  return 0;
}