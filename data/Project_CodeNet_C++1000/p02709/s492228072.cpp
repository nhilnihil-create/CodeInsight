#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll =  long long;
bool cmp(const pair<ll,ll>& a, const pair<ll,ll>& b)
{
    return a.first < b.first;
}

int main()
{

    ll n;

    cin>>n;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
 vector<pair<ll, ll >> a(n) ;
    for(ll i = 0;i<n;i++){

       cin>> a[i].first;
        a[i].second  =  i;

    }
    sort(a.rbegin(),a.rend(),cmp);


ll res =0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
               ll pos =  i+j;
               if(pos==n){
                res = max(res,dp[i][j]);
                break;
               }
 dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + abs(a[pos].second - i) * a[pos].first);
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + abs(a[pos].second - (n - 1 - j)) * a[pos].first);

        }
    }
    cout<<res;

    return 0;
}
