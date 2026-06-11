#include <bits/stdc++.h>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;
typedef pair<int, int> P;

// 奇数の人は奇数、偶数の人は偶数番目にはいる

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S;
  cin >> S;
  int N = S.size();
  int ans[N];
  FOR(i,0,N) ans[i] = 0;

  int cnt[2];
  cnt[0] = 0;
  cnt[1] = 0;
  // ->
  FOR(i,0,N) {
    if (S[i] == 'R') {
      cnt[i%2]++;
    } else {
      ans[i] += cnt[i%2];
      ans[i-1] += cnt[(i-1)%2];
      cnt[0] = 0;
      cnt[1] = 0;
    }
  }


  // <-
  for(int i = N - 1; i >= 0; i--) {
    if (S[i] == 'L') {
      cnt[i%2]++;
    } else {
      ans[i] += cnt[i%2];
      ans[i+1] += cnt[(i+1)%2];
      cnt[0] = 0;
      cnt[1] = 0;
    }
  }

  FOR(i,0,N) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}