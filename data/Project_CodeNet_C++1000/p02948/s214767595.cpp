#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
  int N,M;
  cin>>N>>M;
  vector<vector<int>> work(N,vector<int>(2));
  for(int i = 0;i<N;i++) {
    int x,y;
    cin>>x>>y;
    work[i][0]=y;
    work[i][1]=-x;
  }
  sort(work.begin(),work.end());
  reverse(work.begin(),work.end());
  vector<int> mon(M,0);
  vector<int> lim(M);
  for(int i = 0; i < M; i++) lim[i]=i;
  for(int i = 0; i < N; i++){
    int day=-work[i][1];
    int pay=work[i][0];
    auto ite = upper_bound(lim.begin(),lim.end(),M-day);
    if(ite==lim.begin()) continue;
    mon[*(ite-1)]=pay;
    lim.erase(ite-1);
  }
  ll ans = 0LL;
  for(auto x:mon) ans+=x;
  cout<<ans<<endl;
}