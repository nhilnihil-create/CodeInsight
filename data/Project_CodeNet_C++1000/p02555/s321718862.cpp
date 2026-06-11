#include<bits/stdc++.h>

#define Bye return 0
#define ll long long

using namespace std;
ll s;
const ll M = 1e9+7;

vector<ll> dp (2010, -1);

int rec(ll sum){
    if(sum>s) return 0;
    if(sum == s) return 1;

    if(dp[sum] != -1) return dp[sum];

    ll total = 0;
    for (ll i=3; i<=s; i++)
        if(i+sum<=s)
            total = (total + rec((sum+i)%M))%M;

    return (dp[sum] = total);
}

void solve(){
    cin>>s;
    ll res = rec(0);
    cout<<res<<endl;
}

int main(){
    solve();
    Bye;
}