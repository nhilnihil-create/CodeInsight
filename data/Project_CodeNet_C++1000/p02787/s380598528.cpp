#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
typedef long long ll;
typedef long double ld;

int main(){
    ll H,N;
    cin >> H >> N;
    vector<ll> A(N,0);
    vector<ll> B(N,0);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];
    ll max_A = 0;
    for(int i = 0; i < N; i++) max_A = max(max_A,A[i]);
    vector<ll> dp(H + max_A + 1 ,0);
    for(int j = 0; j < H + max_A + 1; j++) dp[j] = 10000000007;

    dp[0] = 0;
	for(int i = 1; i < H + max_A + 1; i++){
		for(int j = 0; j < N; j++){
			if(i - A[j] <= 0)
				dp[i] = min(dp[i], B[j]);
			else{
				dp[i] = min(dp[i], dp[i - A[j]] + B[j]);
			}            
        }
    }
    ll ans = 10000000007;
    for(int i = H; i < H + max_A + 1; i++){
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;

}