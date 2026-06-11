#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define prvsort(v) sort(v.begin(), v.end(), greater<pair<ll, ll>>())
#define ll long long
#define ld long double
#define fixset(val) fixed << setprecision(10) << val 
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define mod 1000000007
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())

using namespace std;

int main()
{
  string S; cin >> S;
  ll Q, T, F; cin >> Q;
  bool rev = false;
  char C;
  string S1 = "", S2 = "";
  rep(i, 0, Q) {
  	cin >> T;
    if (T == 1) {
    	if (rev) rev = false;
      	else rev = true;
    } else if (T == 2) {
    	cin >> F >> C;
      	if (F == 1) {
        	if (rev) S2 += C;
          	else S1 += C;
        } else if (F == 2) {
        	if (rev) S1 += C;
          	else S2 += C;
        } 
    }
  }
  if (rev) {
    reverse(S2.begin(), S2.end());
    reverse(S.begin(), S.end());
    cout << S2 << S << S1 << endl;
  } else {
    reverse(S1.begin(), S1.end());
    cout << S1 << S << S2 << endl;
  }
}