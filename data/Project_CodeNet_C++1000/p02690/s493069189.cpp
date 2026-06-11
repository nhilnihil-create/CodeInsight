#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int X;
  cin>>X;
  for(int i=0;i<100;i++)
    for(int j=0;j<100;j++)
      if(i*i*i*i*i+j*j*j*j*j==X){
        cout<<i<<' '<<0-j<<endl;
        return 0;
      }
  for(int i=1;;i++){
    for(int j=i;j>=0;j--){
      if(i*i*i*i*i-j*j*j*j*j==X){
        cout<<i<<' '<<j<<endl;
        return 0;
      }
      if(i*i*i*i*i-j*j*j*j*j>=X)
        break;
    }
  }
}