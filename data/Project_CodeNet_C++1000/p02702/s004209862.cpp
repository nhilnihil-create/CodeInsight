#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define	REP(i,n) for(int i = 0;	i < (int)(n); i++)


int main() {
  const	int MOD	= 2019;
  string S; cin>>S;
  long long ans = 0;
  vector<int> cnt(MOD, 0);
  int base = 1;
  int rem = 0;
  cnt[0] = 1;
  for(int i = S.length() - 1; i >= 0; i--) {
    int	v = S[i] - '0';
    rem = rem + base * v;
    rem %= MOD;
    //    cout << rem << " " << cnt[rem] << endl;                               
    if(v  != 0) ans += cnt[rem];
    cnt[rem]++;
    base = (base	* 10) % MOD;
  }
  cout << ans << endl;

  return 0;
}
