//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
typedef pair<int, pi> node;
#define oset tree<pi, null_type,greater<pi>, rb_tree_tag,tree_order_statistics_node_update>

#define N 100005
lli dp[N][15], mod = 1e9+7;
string s;


int main()
{
    cin >> s;
    //s = '#'+s;
    int num = 0;// = s[1]-'0';
    if(s[0] == '?'){
        for(int i=0; i<10; i++){
            dp[0][i] = 1;
        }
    }
    else{
        num = s[0]-'0';
        dp[0][num] = 1;
    }
    int n = s.size();
    for(int i=1; i<n; i++){
        if(s[i] == '?'){
            for(int j=0;j<13; j++){
                for(int k=0; k<10; k++){
                    num = (j*10+k)%13;
                    dp[i][num] = (dp[i][num]+dp[i-1][j]) % mod;
                }
            }
        }
        else{
            for(int j=0; j<13; j++){
                num = s[i]-'0';
                num = (j*10+num)%13;
                dp[i][num] = (dp[i][num]+dp[i-1][j]) % mod;
            }
        }
    }
    cout << dp[n-1][5] << "\n";

    return 0;
}
