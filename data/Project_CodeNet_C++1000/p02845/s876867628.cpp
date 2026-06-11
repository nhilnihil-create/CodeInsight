#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i = 0; i < (int)(n); i++)


const ll MOD = 1000000007LL;

int main() {
  int N; cin>>N;
  vector<int> A(N), cnt(N+1, 0);
  REP(i,N) {
    cin>>A[i];
  }
  cnt[0] = 3;
  ll ans = 1;
  REP(i, N) {
    ans *= (ll)cnt[A[i]];
    ans %= MOD;
    cnt[A[i]]--;
    cnt[A[i]+1]++;
  }
  ans %= MOD;
  cout << ans << endl;
  return 0;
}
