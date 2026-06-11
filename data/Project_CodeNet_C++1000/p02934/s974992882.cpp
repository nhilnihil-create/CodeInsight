#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define len(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> pll;

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
template<typename T>
inline T mod(T n, T mod){ T res = n%mod; if(res < 0) res += mod; return res; }
 
////////////////////////// Solution starts below. //////////////////////////////

int main(){
  fastio;
  int n;
  cin >> n;
  vector<double> v(n);
  double sum = 0;
  for(auto& x : v){
    cin >> x;
    sum += (1/x);
  }
  cout << setprecision(10) << fixed << 1/sum << endl;
  return 0;
}