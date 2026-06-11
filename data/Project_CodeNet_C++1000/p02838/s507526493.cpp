/*
 _ _ _   _    _   _    _   _ _ _   _    _   _ __ _   __       __
|  _ _| | |  | | | |  | | |  _  | | |  | | |  __  | |   \   /   |
| |_ _  | |__| | | |  | | | |_| | | |__| | | |__| | | |\ \_/ /| |
|_ _  | |  __  | | |  | | |  _ <  |  __  | |  __  | | | \   / | |
 _ _| | | |  | | | |__| | | |_| | | |  | | | |  | | | |  \_/  | |  _   _   _
|_ _ _| |_|  |_| |_ __ _| |_ _ _| |_|  |_| |_|  |_| |_|       |_| |_| |_| |_|

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";
#define endl "\n"
const int  MOD=1000000007;
const int N=100010;

ll powMod(ll x,long n){
    ll res=1;
    while(n){
        if(n&1)
            res=(res*x)%MOD;
        x=(x*x)%MOD;
        n/=2;
    }
    return res;
}

void solve(){
    ll ans=0;
    int n;
    cin>>n;
    vector<long> ZERO(64,0),ONE(64,0);

    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        for(int j=0;j<64;j++){
            if(x>>j & 1) ONE[j]++;
            else ZERO[j]++;
        }
    }

    for(int i=0;i<64;i++){
        ans=(ans+((ONE[i]*ZERO[i])%MOD*powMod(2LL,i)%MOD))%MOD;
    }

    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t = 1;
    // cin>>t;
    for (long int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}
