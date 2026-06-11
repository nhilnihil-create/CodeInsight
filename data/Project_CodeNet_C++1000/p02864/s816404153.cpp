#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vpii         vector<pair<int,int>>
#define gph          map<int, vector<int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define FORS(i, n) for(; i < (int)(n); i++)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define printArr(A,n) { cout << #A << " = "; FOR(i,n) cout << A[i] << ' '; cout << endl; }
using namespace std;
#define int long long int
int dp[310][310] = {0};
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n; 
    int rem;cin >> rem;
    vi in(n);
    FOR(i, n)cin >> in[i];
    if(n == rem){
        cout << 0 << endl;
        return 0;
    }
    int prev = 0;
    FOR(i, n){
        if(in[i] > prev){
            dp[i][0] = in[i] - prev + dp[max(i-1, 0LL)][0];
        }else{
            dp[i][0] = dp[max(i-1, 0LL)][0];
        } 
 //       cout << dp[i][0] << " "; 
        prev = in[i];
    }
  //  cout << endl;
    for(int k = 1; k <= rem; k++){
        for(int i = 0; i < n; i++){
            //computing dp[i][k];
            if(i + 1 <= k){
               dp[i][k] = in[i]; 
               continue;
            }
            int & ans= dp[i][k];
            ans = 1e18;
            int h = in[i];
            for(int las = 0; las <= k; las++){
                int prev = i - las - 1;
                if(prev < 0){
                    ans = min(ans, h);
                    break;
                }
                int pH = in[prev];
                ans = min(ans, max(h- pH, 0LL) + dp[prev][k - las]);
            }
//            cout<< dp[i][k] << " ";
        }
//    cout <<endl;
    }
    int ans = 1e18;
    for(int i =0; i <= rem;i++){
        ans = min(ans, dp[n-1-i][rem-i]);
    }
    cout << ans;
}


