#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<numeric>
using namespace std;
#define INF (1 << 30) - 1
#define LINF 1LL << 60
const int MOD = 1000000007;
using ll = long long;
using P = pair<int, int>;

map<ll, int> prime_factorize(ll m){
	map<ll, int> ret;
	for(ll i = 2; i * i <= m; ++i){
		while(m % i == 0){			
			++ret[i];
			m /= i;
		}
	}
	if(m != 1)ret[m] = 1;
	return ret;
}

int main(){
  ll n;
  cin >> n;

  int ans = 0;
  auto factors = prime_factorize(n);
  for(auto f : factors){
  	int c = f.second;
  	int i = 1;
  	while(i <= c){
  		c -= i;
  		++i;
  		++ans;
  	}
  }

  cout << ans << endl;
  return 0;
}
