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
    ll n,i,j,req;
    cin >> n >> req;
    vector<ll>vis(n+5,-1),Coun(n+5),v(n+2);
    for(i = 1; i <= n; i++)cin>>v[i];
    ll cycle = 1, cur = 1, in = 1, cou = 1, before = 0;
    while(true){
        if(vis[cur] != -1){
            before = vis[cur] - 1;
            cycle =  cou - vis[cur];
            break;
        }
        else {
            Coun[in] = cur;
            in++;
            vis[cur] = cou;
            cou++;
            cur = v[cur];
        }
    }
   // mtv(cycle)
    req ++;
    if(req <= before){
        cout << Coun[req] << nl;
        return;
    }
    req -= before;
    req %= cycle;
    if(req == 0)req = cycle;
  //  mtv(before + req)
    cout << Coun[before + req] << nl;
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
