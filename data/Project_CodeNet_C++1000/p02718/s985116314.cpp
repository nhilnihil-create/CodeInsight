#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,M,g=0;
  cin>>N>>M;
  vector<int> A(N);
  for(int &i:A){
    cin>>i;
    g+=i;
  }
  int ans=0;
  for(int &i:A)
    if(i*4*M>=g)
      ans++;
  cout<<(ans>=M?"Yes":"No")<<endl;
}