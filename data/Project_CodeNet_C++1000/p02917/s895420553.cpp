#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<int> B(N-1);
  for(int &i:B)
    cin>>i;
  int ans=B[0]+B[N-2];
  for(int i=1;i<N-1;i++)
    ans+=min(B[i],B[i-1]);
  cout<<ans<<endl;
}