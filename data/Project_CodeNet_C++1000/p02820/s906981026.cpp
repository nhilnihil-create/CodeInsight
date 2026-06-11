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
  int n, k, r, s, p;
  string t;
  cin >> n >> k >> r >> s >> p >> t;
  map<char, int> score;
  score['r'] = p;
  score['s'] = r;
  score['p'] = s;

  int ans = 0;
  vector<bool> used(n, false);
  for(int i = 0; i < n; ++i){
  	if(i - k >= 0){
  		if(t[i] == t[i - k] && used[i - k])continue;
  	}
  	ans += score[t[i]];
  	used[i] = true;
  }

  cout << ans << endl;
  return 0;
}
