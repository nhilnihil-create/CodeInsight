#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int x,y;
  cin>>x>>y;
  
  if(y%2!=0){cout<<"No"<<endl;return 0;}
  
  int cnt=y/2;
  if(cnt==x){cout<<"Yes"<<endl;return 0;}
  while(y>=4){
    y-=4;
    cnt--;
    if(cnt==x){cout<<"Yes"<<endl;return 0;}
  }
  cout<<"No"<<endl;
 
  return 0;
}