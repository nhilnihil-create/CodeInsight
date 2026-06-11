#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef pair<int64, int64> pii;
int64 dp[2002][2002];
int main(){
	int n; cin >> n;
    vector<pii> A(n);
    for(int64 i = 0; i < n; i++){
    	cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());

    int64 ans = 0;
    //memset(dp, 0, sizeof(dp));
  	for(int64 l = n; l >= 1; l--){
    	for(int64 i = 0; i < n - l + 1; i++){
          int64 j = i + l - 1;
          if(l == 1){
          	  ans = max(ans, dp[i][j] + (int64)A[l - 1].first * abs(A[l - 1].second - i));
          }
          else{
          	  dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + A[l - 1].first * abs(A[l - 1].second - i));
              dp[i][j - 1] = max(dp[i][j - 1], dp[i][j] + A[l - 1].first * abs(A[l - 1].second - j));
          }
        }
    }
    cout << ans << endl;
    return 0;
}
