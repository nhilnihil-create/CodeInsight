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
    ll n,i,j,cur = 1,ans;
    cin >> n;
    ans = 0;
    rep(i,0,n){
        cin >> j;
        if(j == cur){
            cur++;
        }
        else {
            ans++;
        }
    }
    if(ans == n)ans = -1;
    cout << ans;
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
