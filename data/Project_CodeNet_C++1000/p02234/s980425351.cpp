#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1LL << 30;

int N;
vll m(110), n(110);
vvll dp(110, vll(110, INF));

ll res(int l, int r){ //[l, r)での最小回数
  if(dp.at(l).at(r) != INF) return dp.at(l).at(r);
  if(r-l == 1) return dp.at(l).at(r) = 0;
  if(r-l == 2) return dp.at(l).at(r) = m.at(l) * n.at(l) * n.at(r-1);

  ll result = INF;
  for(int i = l+1; i <= r-1; i++){ //[l, i), [i, r)に分割
    chmin(result, res(l, i) + res(i, r) + m.at(l) * m.at(i) * n.at(r-1));
  }
  return dp.at(l).at(r) = result;
}

int main(){
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> m.at(i) >> n.at(i);
  }

  cout << res(0, N) << endl;
}
