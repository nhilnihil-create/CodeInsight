#include<iostream>
#include<unordered_map>
#include<bitset>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<ctype.h>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<queue>
#include<limits>
#include<map>
#include<stack>
#include<iterator>
#include<cstring>
 
#include<deque>
#define pi 3.141592653589793238
#include<chrono>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
 
#define mt make_tuple
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
 
#define db double
using namespace std;
 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;
    
    //cin >> T;
    while (T--) {
        string s;
        cin >> s;
        ll n = s.length();
        vector<vector<ll>> dp(n + 1, vector<ll>(2, -INF));
        vector<vector<ll>> parent(n + 1, vector<ll>(2));
        dp[0][0] = -INF, dp[0][1] = 0;
        for(i = 0 ; i < n; i++){
            if(s[i] == '?'){
                if(dp[i][0] + 2 > dp[i][1] + 1){
                    parent[i + 1][1] = 0;
                }
                else{
                    parent[i + 1][1] = 1;
                }
                dp[i + 1][1] = max(dp[i][0] + 2, dp[i][1] + 1);
                if(dp[i][1] > dp[i][0]){
                    parent[i + 1][0] = 1;
                }
                else{
                    parent[i + 1][1] = 0;
                }
                dp[i + 1][0] = max(dp[i][1], dp[i][0]);
            }
            else if(s[i] == 'P'){
                if(dp[i][0] > dp[i][1]){
                    parent[i + 1][0] = 0;
                }
                else{
                    parent[i + 1][0] = 1;
                }
                dp[i + 1][0] = max(dp[i][0], dp[i][1]);
            }
            else{
                if(dp[i][1] + 1 > dp[i][0] + 2){
                    parent[i + 1][1] = 1;
                }
                else{
                    parent[i + 1][1] = 0;
                }
                dp[i + 1][1] = max(dp[i][1] + 1, dp[i][0] + 2);
            }
        }
        ll start;
        if(dp[n][1] > dp[n][0]){
            start = 1;
        }
        else{
            start = 0;
        }
        vector<char> ans;
        ll N = n;
        while(true){
            if(start == 0){
                ans.pb('P');
            }
            else{
                ans.pb('D');
            }
            start = parent[n][start];
            n--;
            if(ans.size() == N){
                break;
            }
        }
        reverse(ans.begin(), ans.end());
        for(i =0 ; i < N; i++){
            cout << ans[i];
        }
    }
    return 0;
}