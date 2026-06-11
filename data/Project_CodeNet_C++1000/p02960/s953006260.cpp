#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

#define mt make_tuple
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sqr(x) ((ll)(x) * (x))

const ll MOD = 1e9 + 7;

ll dp[100100][13];

int main()
{
    memset(dp, 0, sizeof(dp));
    string s;
    cin >> s;
    const int n = (int)s.size();
    dp[0][0] = 1LL;

    for(int i = 0; i < n; ++i)
    {
        int c;
        if(s[i] == '?')
            c = -1;
        else
            c = s[i]-'0';

        for(int j = 0; j < 10; ++j)
        {
            if(c != -1 && c != j)
                continue;
            for(int k = 0; k < 13; ++k)
            {
                dp[i+1][(k*10+j)%13] =  (dp[i+1][(k*10+j)%13] + dp[i][k]) % MOD;
            }
        }
    }

    cout << dp[n][5] << '\n';

    return 0;
}
