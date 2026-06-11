#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 100000
#define mod 1000000007

using namespace std;
int power(int a, int b, int m)
{
    int ans = 1;
    a %= m;
    while(b){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

int n, k, dp[maxn + 1];
vector <int> d[maxn + 1];

signed main()
{
    
    FLASH

    for(int i = 2; i <= maxn; i++)
        for(int j = i; j <= maxn; j += i) d[j].push_back(i);

    cin>>n>>k;

    dp[1] = 1;

    for(int i = 2; i <= k; i++){
        dp[i]= power(i, n, mod) + mod -  power(i - 1, n, mod);
        dp[i] %= mod;

        for(auto x: d[i]){
            dp[i] += mod - dp[i/x];
            dp[i] %= mod;
        }
    }

    for(int i = 2; i <= k; i++) dp[i] += dp[i - 1];

    int ans = 0, sm = 0;

    for(int i = 1; i <= k; i++){
        sm += dp[i];
        ans += i*dp[k/i];
        ans %= mod;
    }
    cout<<ans<<'\n';
}