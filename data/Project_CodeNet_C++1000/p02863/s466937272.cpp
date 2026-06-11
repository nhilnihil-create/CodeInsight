
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> P;
#define rep(i,n) for(ll i=0;i<n;++i)

int main(){
  int n,t;
  cin>>n>>t;
  vector<P> A(n);
  rep(i,n){
    int a1,b1;
    cin>>a1>>b1;
    A[i]=make_pair(a1,b1);
  }
  sort(A.begin(),A.end());
  vector<vector<int>> d(7000,vector<int>(7000,0));
  int ans=0;
  rep(i,n){
    rep(j,t){
      int time=A[i].first;
      int cost=A[i].second;
    d[i+1][j]=max(d[i+1][j],d[i][j]);

    if ((j+time)<=t-1)
    d[i+1][j+time]=max(d[i+1][j+time],d[i][j]+cost);

  //  cout<<ans<<' '<<i+1<<'i'<<j+time<<'j'<<endl;
  //  cout<<d[i+1][j+time]<<' '<<i+1<<' '<<j+time<<endl;
  }
  ans=max(ans,d[i][t-1]+A[i].second);
  }
  cout<<ans;






  }
