#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int W,H,x,y;
  cin>>H>>W>>x>>y;
  cout<<fixed<<setprecision(1)<<H*W*0.5<<' ';
  cout<<(x*2==H && y*2==W?1:0)<<endl;
}