#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MOD = (ll)1e9 + 7;
const int N = (int)1e5 + 9;
ll pwr[N];

int main(){
  fastIO;
  string t;
  cin >> t;
  int n = t.size();
  ll par = 0;
  pwr[0] = 1;
  for(int i = 1; i < n; i ++ ){
    pwr[i] = (pwr[i - 1] * 3ll) % MOD;
    par += pwr[i - 1];
    par %= MOD;
  }
  ll y = 1;
  for(int i = 1 ; i < n; i ++ ){
    if(t[i] == '1'){
      par += (y*pwr[n - i - 1])%MOD;
      par %= MOD;
      y = (y * 2ll) % MOD;
    }
  }
  par=(par+y)%MOD;
  par=(par*2ll)%MOD;
  par=(par+1)%MOD;
  cout << par << "\n";
  return 0;
}