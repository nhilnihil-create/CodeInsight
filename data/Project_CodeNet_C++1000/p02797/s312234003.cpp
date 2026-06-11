#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
using Graph = vector<vector<int>>;


int main() {
  ll n, k, s; cin >> n >> k >> s;
  if(s != 1e9){
    rep(i, 0, k) cout << s << " ";
    rep(i, 0, n-k){
      if(i) cout << " ";
      cout << s+1;
    }
    cout << endl;
  }else{
    rep(i, 0, k) cout << s << " ";
    rep(i, 0, n-k){
      if(i) cout << " ";
      cout << 1;
    }
    cout << endl;
  }

  return 0;
}
