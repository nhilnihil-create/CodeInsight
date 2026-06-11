#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf = 1LL<<60;
const int mod = 1e9 + 7;
const double eps = 1e-9;

/*{
  }*/

signed main(){
  int n;
  cin >> n;

  vvi ans(n, vi(n));
  rep(i, 0, n) rep(j, 0, n) if(ans[i][j] == 0){
    rep(k, 0, 10) if((i & 1<<k) != (j & 1<<k)){
      ans[i][j] = k;
      break;
    }
  }

  rep(i, 0, n){
    rep(j, i+1, n){
      cout << ans[i][j]+1 << " \n"[j==n-1];
    }
  }

  return 0;
}

