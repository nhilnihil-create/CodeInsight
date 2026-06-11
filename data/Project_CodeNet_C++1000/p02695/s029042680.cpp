#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define reps(i,n) for (int i=1;i<=(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rreps(i,n) for (int i=(n);i>0;i--)
#define all(v) (v).begin(),(v).end()
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>
template<class T> inline bool chmin(T &a, T b) {if (a>b) {a = b; return 1;} return 0;};
template<class T> inline bool chmax(T &a, T b) {if (a<b) {a = b; return 1;} return 0;};
typedef long long int ll;
const long long INF = 1LL << 60;


int main(){
  int N, M, Q; cin >> N >> M >> Q;
  int a[Q], b[Q], c[Q], d[Q];
  rep(i,Q) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    --a[i], --b[i];
  }

  vector<vector<int>> U;

  queue<vector<int>> q;
  reps(i,M) q.push(vector<int>(1,i));

  while (!q.empty()){
    auto vec = q.front(); q.pop();
    // cout << vec.size() << endl;
    if (vec.size()==N) {
      U.push_back(vec);
      continue;
    }
    int l = vec.back();
    for (int j=l;j<=M;j++){
      auto vec_c = vec;
      vec_c.push_back(j);
      q.push(vec_c);
    }
  }


  ll ans = 0;
  for (auto vec : U){
    ll tmp = 0;
    rep(i,Q){
      if (vec[b[i]] - vec[a[i]]==c[i]) tmp += d[i];
    }
    chmax(ans, tmp);
  }
  cout << ans << endl;
  
  // cout << fixed << setprecision(10);
  
  return 0;
}