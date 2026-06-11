#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1000000007;
signed main(){
  int N;
  cin>>N;
  vector<int> A(N);
  A[0]=3;
  int ans=1;
  while(N--){
    int a;
    cin>>a;
    ans=ans*A[a]%mod;
    A[a]--,A[a+1]++;
  }
  cout<<ans<<endl;
}