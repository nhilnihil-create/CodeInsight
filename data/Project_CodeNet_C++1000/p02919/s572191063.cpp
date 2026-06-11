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
#include<set>

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
// const long long INF = 1LL<<60;
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
   int N;
   cin >> N;
   ll P[N + 1], pos[N + 1];
   for (int i = 0; i < N; i++) {
      cin >> P[i];
      pos[P[i]] = i + 1;
   }
   ll ans = 0;

   multiset<ll> s;
   s.insert(0);
   s.insert(0);
   s.insert(N + 1);
   s.insert(N + 1);

   for (ll now = N; now >= 1; now--) {
      auto it = s.lower_bound(pos[now]);
      
      ll pos_r = *it;
      it++;
      ll pos_rr = *it;
      it--;
      it--;
      ll pos_l = *it;
      it--;
      ll pos_ll = *it;

      ans += now * (pos_r - pos[now]) * (pos_l - pos_ll);
      ans += now * (pos_rr - pos_r) * (pos[now] - pos_l);

      s.insert(pos[now]);
   }
   cout << ans << endl;
   return 0;
}
