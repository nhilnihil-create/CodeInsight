#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using ll = long long;
using namespace std;

const long long MOD = 1000000007;
const ll LINF = 1LL << 50;

int main() {
  int N;
  cin >> N;
  vector<int> nums(100001,0);
  REP(n,N){
    int d;
    cin >> d;
    nums[d] += 1;
  }

  int ans = 0;
  int nL = 0;
  int nR = N;

  REP(n,100001){
    int k = n+1;
    nL += nums[k];
    nR -= nums[k];
    if (nL == nR) ans += 1;
  }
  cout << ans << endl;

}
