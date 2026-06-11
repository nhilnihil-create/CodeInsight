#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;

/* short */
#define pb push_back
#define mp make_pair
#define Fi first
#define Se second
#define ALL(v) begin(v), end(v)
#define RALL(v) rbegin(v), rend(v)

/* REPmacro */
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOREACH(x, a) for(auto x : a)

/* exchange */
#define CHMIN(a, b) (a) = min((ll)(a), (ll)(b))
#define CHMAX(a, b) (a) = max((ll)(a), (ll)(b))

/* function */
#define IN(x) cin >> x
#define DEBUG(x) cerr << (x) << " "
#define LN() cerr << "\n"
#define PRINT(x) cout << (x) << endl
#define BR cout << endl

/* const */
const int ARRAY = 100005;
const int INF = 1001001001; // 10^9
const ll LINF = 1001001001001001001; // 10^18
const int MOD = 1e9 + 7;

ll N, M;
ll ret = 0;
string s;

int main(void){
  
  IN(N);
  IN(M);

  ll l = 1;
  ll r = l + (M%2==1 ? M : M-1);
  while(r > l) {
    cout << l << " " << r << endl;
    l++;
    r--;
  }
  r = 2 * M + 1;
  l = r - (M%2==0 ? M : M-1);
  while(r > l) {
    cout << l << " " << r << endl;
    l++;
    r--;
  }

}
