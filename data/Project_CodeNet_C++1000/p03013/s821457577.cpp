#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define arr array

using namespace std;

const int e = 2e6 + 69;
const ll mod = 1e9 + 7;

ll a[e], dp[e];

//beginner 1999 129

int n, m;

int main()
{
     cin >> n >> m;
     for(int i=1; i<=m; i++){
         int x;
         cin >> x;
         a[x] = 1;
     }
     dp[0] = 1;
     for(int i=1; i<=n; i++){
         if(a[i-1] == 0) dp[i] += dp[i-1];
         if(a[i-2] == 0) dp[i] += dp[i-2];
         dp[i] %= mod;
     }
     cout << dp[n];
}
