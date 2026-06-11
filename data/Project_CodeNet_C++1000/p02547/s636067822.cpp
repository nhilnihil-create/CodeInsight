#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,n) for(ll i=0; i<int(n); ++i)
#define all(v) (v).begin(), (v).end()
#define ff first
#define ss second
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define MOD 1000000007
typedef long long ll;

void solve()
{
    int n;
    cin>>n;
    vector<pii> v(n);
    For(i,n) cin>>v[i].ff>>v[i].ss;
    bool fg=false;
    for(int i=2; i<n; i++)
    {
        if(v[i-2].ff==v[i-2].ss && v[i-1].ff==v[i-1].ss && v[i].ff==v[i].ss)
        {
            fg = true;
        }
    }
    cout<<(fg?"Yes":"No")<<endl;
}

int main(){
    optimize();
    ll T=1;
    //cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
