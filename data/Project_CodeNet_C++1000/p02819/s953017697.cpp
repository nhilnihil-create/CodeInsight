#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int X;
  cin>>X;
  while(true){
    for(int i=2;i<=X/i;i++)
      if(X%i==0)goto home;
    cout<<X<<endl;
    return 0;
    home:;
    X++;
  }
}