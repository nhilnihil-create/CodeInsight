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
#define oset tree<pi, null_type,greater<pi>, rb_tree_tag,tree_order_statistics_node_update>

#define N 105
vector<string> gr;
int dp[N][N];

int main()
{
    int h, w;
    cin >> h >> w;
    for(int i=0; i<h; i++){
        string s;
        cin >> s;
        gr.push_back(s);
    }
    if(gr[0][0] == '#') dp[0][0] = 1;

    for(int i=1; i<w; i++){
        if(gr[0][i] == '#' && gr[0][i-1] == '.'){
            dp[0][i] = dp[0][i-1]+1;
        }
        else{
            dp[0][i] = dp[0][i-1];
        }
    }
    for(int i=1; i<h; i++){
        if(gr[i][0] == '#' && gr[i-1][0] == '.'){
            dp[i][0] = dp[i-1][0]+1;
        }
        else{
            dp[i][0] = dp[i-1][0];
        }
    }
    for(int i=1; i<h; i++){
        for(int j=1; j<w; j++){
            if(gr[i][j] == '#'){
                if(gr[i-1][j] == '.' && gr[i][j-1] == '.'){
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1;
                }
                else if(gr[i-1][j] == '.'){
                    dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]);
                }
                else if(gr[i][j-1] == '.'){
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]+1);
                }
                else{
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                }
            }
            else {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[h-1][w-1] << "\n";

    return 0;
}
