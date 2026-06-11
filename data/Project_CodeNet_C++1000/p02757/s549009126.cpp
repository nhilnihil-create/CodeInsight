#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) (int)(v).size()
#define vi vector<int>

using namespace std;

typedef long long ll;
typedef long double ld;

using P = pair<int, int>;
template<typename T>
struct Edge {
    int u, v;
    T cost;
    Edge(int u, int v, T c) : u(u), v(v), cost(c) {}
    bool operator< (const Edge &e) const {return cost < e.cost;}
};

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;

ll ans;

int main(void) {
  int N;
  ll P;
  string S;
  cin >> N >> P >> S;
  if (P==2) {
    per(i, 0, N) {
      ll d = (ll)(S[i]-'0');
      if (d%2==0) ans += i+1;
    } 
  } else if (P==5) {
    per(i, 0, N) {
      ll d = (ll)(S[i]-'0');
      if (d==5 || d==0) ans += i+1;
    } 
  
  } else {
    ll dw = 1, num = 0;
    map<ll, ll> m;
    m[0]++;
    
    per(i, 0, N) {
      ll d = (ll)(S[i]-'0');
      num  = (((d*dw)%P)+num)%P;
      ll r  = num%P;
      ans += m[num];
      m[num]++;
      dw = (dw*10)%P;
    }
    
  
  }
  

    cout << ans << endl;
    
    return 0;
}



