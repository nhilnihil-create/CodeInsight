#include<bits/stdc++.h>
#define endl '\n';
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 9e18;
constexpr int inf = 1e9;
constexpr double INFD = 1e100;
constexpr ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ---------------------------------------------------------------------------

int main(){
  int N,K;
  cin >> N >> K;
  if((N-1)*(N-2)/2 < K){
    cout << -1 << endl;
    return 0;
  }
  vector<P> ans;
  for(int i=2; i<=N; i++){
    ans.emplace_back(1,i);
  }
  int vi=2,vj=3;
  for(int i=0; i<(N-1)*(N-2)/2-K; i++){
    ans.emplace_back(vi,vj);
    if(vj == N){
      vi++;
      vj = vi;
    }
    vj++;
  }
  cout << ans.size() << endl;
  for(int i=0; i<ans.size(); i++){
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}