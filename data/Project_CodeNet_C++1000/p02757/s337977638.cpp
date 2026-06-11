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

int main(){
  int n, p;
  cin >> n >> p;
  string s;
  cin >> s;

  ll ans = 0;
  if(p == 2 || p == 5){
  	for(int i = n - 1; i >= 0; --i){
  		if((s[i] - '0') % p == 0)ans += i + 1;
  	}
  }
  else{
  	vector<ll> cnt(p, 0);
  	int tens = 1;
    int mods = 0;
  	for(int i = n - 1; i >= 0; --i){
  		(mods += (s[i] - '0') * tens) %= p;
  		(tens *= 10) %= p;
  		++cnt[mods];
  	}

  	for(int i = 0; i < p; ++i){
  		ans += cnt[i] * (cnt[i] - 1) / 2;
  		if(i == 0)ans += cnt[i];
  	}
  }

  cout << ans << endl;
  return 0;
}
