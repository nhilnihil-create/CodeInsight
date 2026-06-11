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
  string s, t, u;
  int a, b;
  cin >> s >> t >> a >> b >> u;
  if(u == s)--a;
  else --b;
  cout << a << " " << b << endl;
  return 0;
}
