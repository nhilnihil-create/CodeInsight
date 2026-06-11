#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

ll dp[100010][2];
int main()
{
    string str;
    cin >> str;
    vector<int> l;
    int len = str.length();
    rep(i,(int)len)
    {
        l.push_back(str[i]-'0');
    }
    dp[0][0] = 1;    
    rep(i,len)
    {
        (dp[i+1][1] += dp[i][1]*3%MOD)%=MOD;
        if (l[i]==1)
        {
            (dp[i+1][1] += dp[i][0]%MOD)%=MOD;
            (dp[i+1][0] += dp[i][0]*2%MOD)%=MOD;
        }

        if (l[i]==0)
        {
            (dp[i+1][0] += dp[i][0]%MOD)%=MOD;
        }
    }
    cout << (dp[len][0]+dp[len][1])%MOD<< endl;
}