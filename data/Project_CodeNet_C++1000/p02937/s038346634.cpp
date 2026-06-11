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
  string s, t;
  set<int> pos[27];
  cin >> s >> t;
  for(int i = 0; i < len(s); i++){
    pos[s[i]-'a'].insert(i);
  }
  ll ans = 0;
  int p = -1;
  for(int i = 0; i < len(t); i++){
    if(pos[t[i]-'a'].empty()){
      cout << -1 << endl;
      return 0;
    }
    auto it = pos[t[i]-'a'].upper_bound(p);
    if(it == pos[t[i]-'a'].end()){
      ans += 1LL*(len(s) - p) + *pos[t[i]-'a'].begin(); // pega tudo + 1° ocorrencia
      p = *pos[t[i]-'a'].begin();  // vai pra la
    }else{
      ans += *it - p; // anda pra *it
      p = *it; // vai pra it
    }
  }
  cout << ans << '\n';
  return 0;
}