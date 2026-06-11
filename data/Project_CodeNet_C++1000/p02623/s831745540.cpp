#include <bits/stdc++.h>
using namespace std;
    
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, n) for (int i = 0; i < n; i++)
#define repn(i, a, b) for (int i = a;i<=b;i++)
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(x) memset(x, 0, sizeof(x))
#define ritr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define pai pair < int, int> 
#define pal pair < ll, ll> 
#define vi vector <int> 
#define vl vector < ll > 
#define vpai vector < pii > 

const int mod = 1e9+7;
const int INF = INT_MAX;
const int sze = 3005;

void solve() {
    int n,m;
    cin>>n>>m;
    ll time;
    cin>>time;

    ll a[n],b[m];
    
    rep(i,n) cin>>a[i];
    rep(i,m) cin>>b[i];

    vl aa(n+1,0),bb(m+1,0);
    //aa[0]=a[0],bb[0]=b[0];

    repn(i,1,n) aa[i]=a[i-1]+aa[i-1];
    repn(i,1,m) bb[i]=b[i-1]+bb[i-1];

    // rep(i,n+1) cout<<aa[i]<<" ";
    // cout<<endl;
    // rep(i,m+1) cout<<bb[i]<<" ";
    // cout<<endl;

    int count=0;
    ll curr=0,mx=0;
    ll temp=time;
    for(int i=0;time-aa[i]>=0&&i<=n;i++){
        ll x=lower_bound(all(bb),time-aa[i])-bb.begin();
        if(time-aa[i]<bb[x]) x--;
        if(x<0) continue;
        mx=max(mx,min(x,(ll)m)+i);
    }
    time=temp;
    for(int i=0;time-bb[i]>=0&&i<=m;i++){
        ll x=lower_bound(all(aa),time-bb[i])-aa.begin();
        if(time-bb[i]<aa[x]) x--;
        if(x<0) continue;
        mx=max(mx,min(x,(ll)n)+i);
    }
    cout<<mx<<endl;
}

int main() {
    IOS;

    int t = 1;
    // cin >> t;
    while (t--) {
       solve();
    }

  return 0;
}