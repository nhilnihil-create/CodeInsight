#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

/*{
}*/

using vi = vector<int>;
using vvi = vector<vi>;
using P = pair<int,int>;

//constexpr int mod = 1e9+7;
//constexpr int inf = 1LL<<60;

signed main() {
  int m;
  cin >> m;

  int sum = 0, n = 0;
  rep(i, 0, m){
    int d, c;
    cin >> d >> c;
    sum += d*c;
    n += c;
  }

  cout << (n-1 + (sum-1)/9) << endl;

  return 0;
}

