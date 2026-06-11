#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;


int main()
{
  int N; cin >> N;

  vector<int> A(N);
  for(int i=0; i<N; ++i) cin >> A[i];

  sort(A.begin(), A.end());
  
  vector<int> cnt(1000001, 0);
  for(int i=0; i<N; ++i)
    ++cnt[A[i]];

  int ans = 0;
  vector<bool> dp(1000001, true);
  for(int i=0; i<N; ++i)
  {
    if(dp[A[i]] && (cnt[A[i]] == 1))
      ++ans;
    if(dp[A[i]])
    {
      for(int j=A[i]; j<=1000000; j+=A[i])
        dp[j] = false;
    }
  }

  cout << ans << endl;
}
