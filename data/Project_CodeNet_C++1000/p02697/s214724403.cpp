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
  int n, m;
  cin >> n >> m;
  int flg = n % 2 == 0;
  int l = 1, r = n - 1;
  for(int i = 0; i < m; ++i){
  	if(flg && (r - l == n / 2 || r - l == n / 2 - 1))--r;
  	cout << l << " " << r << endl;
  	++l;
  	--r;
  }
  return 0;
}
