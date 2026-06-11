#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define mod 998244353

const ll N = 5005 ;

ll dp[N][N] ;

int main() {
    ll x = 1 , n , i , j=0 , ans = 0 ,s ,sum = 0,tot = 0;
    cin >> n >> s ;
    vector<ll> a(n+1) ;
    for(i  = 1 ; i<= n;  i++) {
      cin >> a[i]  ;
    }
    dp[0][0]=1 ;
    for (i = 1; i<= n ; i++) {
        for (j = 0 ; j<= s ; j++) {
            dp[i][j] += 2*dp[i-1][j] ;
            dp[i][j]%=mod ;
            if (j+a[i]<=s) {
                  //  cout << j+a[i] << ' ' <<dp[i][j] << endl ;
                dp[i][j+a[i]] += dp[i-1][j] ;
                dp[i][j+a[i]] %= mod ;
                //cout << dp[i][j+a[i]] << ' ' << i << ' ' << j+a[i] << endl  ;
            }
        }
    }

    cout << dp[n][s]<< endl ;
       return 0 ;
}
