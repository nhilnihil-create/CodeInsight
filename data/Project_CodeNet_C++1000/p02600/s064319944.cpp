#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  if(N<600)cout<<8<<endl;
  else if(N<800)cout<<7<<endl;
  else if(N<1000)cout<<6<<endl;
  else if(N<1200)cout<<5<<endl;
  else if(N<1400)cout<<4<<endl;
  else if(N<1600)cout<<3<<endl;
  else if(N<1800)cout<<2<<endl;
  else cout<<1<<endl;
}