#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int X,Y;cin>>X>>Y;
  int sum=0;
  if(X==1||X==2||X==3)sum+=(4-X)*100000;
  if(Y==1||Y==2||Y==3)sum+=(4-Y)*100000;
  if(X==1&&Y==1)sum+=400000;
  cout<<sum<<endl;
}