#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using vc=vector<char>;
using vvc=vector<vc>;
using pii = pair<int,int>;
using pil = pair<int,ll>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int N,M;
  cin >> N >> M;
  vi A(N),B(N);
  vvi rew(M+1);
  rep(i,N) {
    cin >> A[i] >> B[i];
    if(A[i]<=M) rew[A[i]].push_back(B[i]);
  }
  
  int ans=0;
  priority_queue<int> que;
  rep2(i,1,M+1) {
    for(int x:rew[i]) que.push(x);
    if(!que.empty()) {
      ans+=que.top();que.pop();
    }
  }
  
  cout << ans << endl;
}