#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;

typedef long long ll;

typedef std::pair<int, int> ipair;
bool lessPair(const ipair& l, const ipair& r){return l.second < r.second;}
bool morePair(const ipair& l, const ipair& r){return l.second > r.second;}

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const ll MOD = 1e9 + 7;
//const long long INF = 1LL<<60;
const int INF = 1e9;
void add(long long &a, long long b) { a += b; if (a >= MOD) a -= MOD; }
void sub(long long &a, long long b) { a -= b; if (a < 0) a += MOD; }
void mul(long long &a, long long b) { a *= b; a %= MOD; }
ll llmin(ll a, ll b) { if (a < b) return a; else return b; }
ll llmax(ll a, ll b) { if (a < b) return b; else return a; }
ll llabs(ll a) { if (a >= 0) return a; else return - a; }
ll llmodpow(ll a, ll n) {
   if (n == 0) return 1;
   ll tmp = llmodpow(a, n / 2);
   mul(tmp, tmp);
   if (n & 1) mul(tmp, a);
   return tmp;
}

int main() {
   int N, M;
   cin >> N >> M;
   vector<int> dp((1<<N), INF);
   int a, b;
   int c[N];
   dp[0] = 0;
   for (int i = 0; i < M; i++) {
      memset(c, 0, sizeof(c));
      cin >> a >> b;
      int flg = 0;
      for (int k = 0; k < b; k++) {
         cin >> c[k];
         flg |= (1<<(c[k] - 1));
      }
      // cout << flg << endl;
      for (int j = 0; j < (1<<N); j++) {
         // cout << dp[j] << " " << a << endl;
         chmin(dp[j | flg], dp[j] + a); 
      }
   }
   int ans = dp[(1<<N) - 1];
   if (ans == INF) ans = -1;
   cout << ans << endl;
   return 0;
}
