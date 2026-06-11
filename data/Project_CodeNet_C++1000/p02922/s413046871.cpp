#include <bits/stdc++.h>
using namespace std;

const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)


int main() {
  int a,b;
  int ans =1;
  int c = 0 ;
  cin >> a >> b;
  while (ans < b){
	  ans += a - 1;
	  c++;
  }
  cout << c << endl;
}