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
using pll = pair<ll, ll>;

int main(){
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; ++i){
  	cin >> a[i] >> b[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int mx = b[n/2 - 1] + b[n/2];
  int mn = a[n/2 - 1] + a[n/2];
  if(n % 2){
  	mx = b[n/2];
  	mn = a[n/2];
  }

  int ans = mx - mn + 1;
  
  cout << ans << endl;
  return 0;
}
