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
  ll a, b, k;
  cin >> a >> b >> k;

  ll a2 = max(0ll, a - k);
  k = max(0ll, k - a);
  b = max(0ll, b - k);

  cout << a2 << " " << b << endl;
  return 0;
}
