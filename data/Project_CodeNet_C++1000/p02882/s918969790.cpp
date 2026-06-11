#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<endl;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }

const double PI = acos(-1.0);

int main(int argc, char const *argv[]) {
  double a, b, x;
  cin >> a >> b >> x;
  x /= a;
  cout << fixed << setprecision(10);
  if (x > a*b/2) cout << atan2((a*b-x)*2, a*a) * 180 / PI << endl;
  else cout << atan2(b*b, x*2) * 180 / PI << endl;
  return 0;
}