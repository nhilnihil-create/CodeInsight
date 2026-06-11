#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ld double
#define ll long long
#define all(x) x.begin(),x.end()
const int mod=1e9+7;
#define fi first
#define se second
#define Dracarys  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define inf (ll)1e16

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

void solve(){
    ll h,w;
    cin>>h>>w;
    
    ll dp[h+2][w+2],arr[h+2][w+2];
    memset(dp,0,sizeof(dp));
    memset(arr,0,sizeof(arr));
    
    string s;
    for (ll i=1;i<=h;i++){
        cin>>s;
        for (ll j=1;j<=w;j++){
            if (s[j-1]=='#')
            arr[i][j]=1;
        }
    }
    
    ll cnt=0;
    for (ll i=1;i<=w;i++){
        if (arr[1][i]&&(!arr[1][i-1]))
        cnt++;
        dp[1][i]=cnt;
    }
    
    cnt=0;
    for (ll i=1;i<=h;i++){
        if (arr[i][1]&&(!arr[i-1][1]))
        cnt++;
        dp[i][1]=cnt;
    }
    
    for (ll i=2;i<=h;i++){
        for (ll j=2;j<=w;j++){
            if (arr[i][j]){
                ll ex1=0,ex2=0;
                if (!arr[i][j-1])
                ex1=1;
                if (!arr[i-1][j])
                ex2=1;
                dp[i][j]=min(dp[i][j-1]+ex1,dp[i-1][j]+ex2);
            }
            else
            dp[i][j]=min(dp[i][j-1],dp[i-1][j]);
        }
    }
    
    cout<<dp[h][w]<<"\n";
}

int main() {
    
    Dracarys
    
    ll t=1;
    //cin>>t;
    while(t--){ solve(); }
    
    return 0;
}