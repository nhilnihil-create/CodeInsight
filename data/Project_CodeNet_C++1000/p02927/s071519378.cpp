#include <bits/stdc++.h>
using namespace std;

int main(){
  int m,d,count=0;
  cin>>m>>d;
  if(d<22||m<4){
    cout<<0<<endl;
    return 0;
  }
  for(int j=4;j<=m;j++){
  for(int i=22;i<=d;i++){
    int d1=i%10,d10=i/10;
    if(d1<2) continue;
    else if(d1*d10==j) count++;
  }
  }
  cout<<count<<endl;
}