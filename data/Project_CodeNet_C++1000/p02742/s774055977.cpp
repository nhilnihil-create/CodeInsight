#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int H,W;
  cin>>H>>W;
  if(H==1 || W==1)
    cout<<1<<endl;
  else
    cout<<(H*W+1)/2<<endl;
}