#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"
#define int ll

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N,M;
  cin>>N>>M;
  vector<int>A(N),B(N);
  for(int i=0;i<N;i++)cin>>A[i]>>B[i];
  ll ans=0;
  priority_queue<int>X;
  vector<vector<int>>w(100001);
  for(int i=0;i<N;i++)w[A[i]].push_back(B[i]);
  for(int i=M;i>=1;i--){
    for(auto it:w[M-i+1])X.push(it);
    if(!X.size())continue;
    ans+=X.top();
    X.pop();
  }
  cout<<ans<<endl;
  return 0;
}
