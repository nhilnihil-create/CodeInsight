#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)
 
signed main(){
  int N,M;
  cin>>N>>M;
  vector<int> H(N);
  rep(i,N)cin>>H[i];
  vector<bool> check(N,true);
  rep(i,M){
    int A,B;
    cin>>A>>B;
    A-=1;
    B-=1;
    if(H[A]<=H[B])check[A]=false;
    if(H[B]<=H[A])check[B]=false;
  }
  int ans=0;
  rep(i,N)if(check[i])ans+=1;
  cout<<ans<<endl;
  return 0;
}