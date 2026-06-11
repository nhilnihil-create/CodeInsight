#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mtv(kit) cout<<#kit<<" - "<<kit<<"\n";
#define ff first
#define ss second
#define pb push_back
#define rep(i,a,b) for(i=a;i<b;i++)
#define pii pair<ll , ll>
#define all(x) x.begin(),x.end()
#define nl "\n"
#define ump unordered_map

void doit(){
    ll dp[505],i,j;
    rep(i,0,501){
        dp[i] = pow(i,5);
    }
    ll n,l1,l2;
    cin >> n;
    rep(i,0,501){
        rep(j,0,i){
            if(dp[i] - dp[j] == n){
                cout << i << " " << j << nl;
                return;
            }
        }
    }
    rep(i,0,501){
        rep(j,i,501){
            if(dp[i] + dp[j] == n){
                cout << j << " " << -i << nl;
                return; 
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
   // cin >> t;
    for(ll i = 1; i <= t; i++){
        doit();
    }
}
