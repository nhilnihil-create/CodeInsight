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
const int N=1000100;

vector<bool> prime(N,false);
vector<ll> v;

void pre(){
    prime[0]=prime[1]=true;
    for(ll i=2;i<N;i++){
        if(!prime[i]){
            for(ll j=2LL*i;j<N;j+=i)
                prime[j]=true;
        }
    }
    for(ll i=2;i<N;i++){
        if(!prime[i]){
            v.pb(i);
        }
    }
}

void solve() {
    pre();
    ll x;
    cin>>x;
    auto it=lower_bound(v.begin(),v.end(),x);
    cout<<*it<<endl;
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
