#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B,C,ans=0;
  cin>>A>>B>>C;
  if(B+C>A)ans=B+C-A;
  cout<<ans<<endl;
}