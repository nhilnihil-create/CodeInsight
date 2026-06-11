#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

inline vector<pair<ll,int>> sieve(ll n){
	vector<pair<ll,int>> sosuu;
	for(ll i = 2; i*i <= n; i++){
		int x = 0;
		while(n % i == 0){
			n /= i;
			x++;
		}
		sosuu.push_back(make_pair(i,x));
	}
	if(n != 1) sosuu.push_back(make_pair(n,1));
	return sosuu;
}

inline map<ll, int> sieve2(ll n) {
  map<ll, int> sosuu;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      sosuu[i]++;
      n /= i;
    }
  }
  if (n != 1) sosuu[n] = 1;
  return sosuu;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n; cin >> n;
  // auto res = sieve(n);
  auto res = sieve2(n);
  int ans = 0;
  for(auto x : res){
    int a = x.second, b = 1;
    while(b <= a){
      a -= b;
      b++;
      ans++;
    }
  }
  cout << ans;
  cout << "\n";
  return 0;
}
