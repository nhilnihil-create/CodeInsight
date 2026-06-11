/*
    Author: MEHXM
*/
#include <bits/stdc++.h>
using namespace std;

#define cp_io ios_base::sync_with_stdio(0);cin.tie(0)
#define ll long long int
#define oo 1000000010
#define MAX 1000000
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define nl "\n"

int main()
{
    cp_io;
    #ifndef ONLINE_JUDGE
    freopen("z_input.txt","rt",stdin);
    freopen("z_output.txt","wt",stdout);
    #endif
    int h,w,m;
    cin >> h >> w >> m;

    vector <ll> row(h);
    vector <ll> col(w);
    set <pair<ll,ll>> mat;
    
    ll a,b;
    for(int i=0; i<m; i++)
    {
        cin >> a >> b;
        a--; b--;
        row[a]++;
        col[b]++;
        mat.insert({a,b}); 
    }

    ll rmx = INT_MIN;
    ll cmx = INT_MIN;

    for(int i=0; i<h; i++) rmx = max(rmx, row[i]);
    for(int i=0; i<w; i++) cmx = max(cmx, col[i]);

    ll ans = 0;
    ll c1 = 0, c2 = 0;

    for(int i=0; i<h; i++) if(rmx == row[i]) c1++;
    for(int i=0; i<w; i++) if(cmx == col[i]) c2++;
    
    ll k = c1*c2;

    for(auto it : mat) if(rmx == row[it.ff] && cmx == col[it.ss]) k--;
    
    ans = rmx + cmx;
    if(k==0) ans--;
    cout << ans << nl;
    return 0;
}