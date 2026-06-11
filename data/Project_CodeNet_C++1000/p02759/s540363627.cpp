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
  int n;
  cin >> n;
  if(n % 2)cout << n / 2 + 1 << endl;
  else cout << n / 2 << endl;
  return 0;
}
