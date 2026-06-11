#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
//#define P pair<ll, ll>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;

int
main()
{

  int N, K; cin >> N >> K;
  int R, S, P; cin >> R >> S >> P;
  string s; cin >> s;
  vector<char> t;
  for(auto x: s){
    if(x == 'r'){
      t.push_back('p');
    } else if(x == 'p'){
      t.push_back('s');
    } else {
      t.push_back('r');
    }
  }

  vector<char> pre;
  ll ans = 0;
  ll cnt = 0;
  for(auto x: t){
    if(cnt != 0 && cnt >= K){
      if(pre[cnt - K] == x){
        pre.push_back('n');
        ++cnt;
        continue;
      }
    }
    if(x == 'r'){
      ans += R;
      pre.push_back('r');
    } else if(x == 'p'){
      ans += P;
      pre.push_back('p');
    } else {
      ans += S;
      pre.push_back('s');
    }
    ++cnt;
  }

  cout << ans << endl;


}
