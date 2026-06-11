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
    ll n,i;
    cin >> n;
    vector<pii>v(n+1);    
    rep(i,1,n+1){
        cin >> v[i].ff >> v[i].ss;
    }
    vector<ll>v1(n);
    iota(all(v1),1);
    double ans = 0;
    ll c = 0;
    do{ c++;
        rep(i,1,n){
            ans += sqrt( ( ( (1.0 * v[v1[i]].ss) - (1.0 * v[v1[i-1]].ss) ) * ( (1.0 * v[v1[i]].ss) - (1.0 * v[v1[i-1]].ss) ) )+ 
                      ( ( (1.0 * v[v1[i]].ff) - (1.0 * v[v1[i-1]].ff) ) * ( (1.0 * v[v1[i]].ff) - (1.0 * v[v1[i-1]].ff) ) ) );
        }
    }
    while(next_permutation(all(v1)));
    cout << fixed << setprecision(10) << (ans / (1.0*c))<< nl;
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
