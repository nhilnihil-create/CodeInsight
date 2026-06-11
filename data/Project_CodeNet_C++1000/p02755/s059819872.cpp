#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  bool flag;
  flag=true;
  for(long long int i=1;i<=100000;i++){
    long long int c=i*0.08;
    long long int d=i*0.1;
    if(c==a & d==b){
      cout<<i<<endl;
      flag=false;
      break;
    }
  }
  if(flag){
    cout<<-1<<endl;
  }
  return 0;
}