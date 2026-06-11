#include <bits/stdc++.h>

using namespace std;
 
typedef long long int ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector <string> vs;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef pair<int,int> pi;

#define int ll
#define forl(i,a,b) for (int i = a; i < b; i++)
#define rfor(i,b,a) for (int i = b; i >= a; i--)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define sumup(x) accumulate(x.begin(), x.end(), 0)
#define PI 3.141592653589793238
#define MOD 1000000007
#define loop(n) for(int i = 0; i < n; i++)
#define rloop(n) for(int i = n-1; i >= 0; i--)

void io() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void solve() {
    int n, m;
    cin>>n>>m;
    vl h(n), hm(n);
    loop(n) cin>>h[i];
    //vector <pair<ll,ll>> ab(m,{0,0});
    map <ll,set<ll>> roads;
    loop(m) {
        ll x, y;
        cin>>x;
        cin>>y;
        hm[x-1] = max(hm[x-1],h[y-1]);
        hm[y-1] = max(hm[y-1],h[x-1]);
    }
    int ans=0;
    loop(n) {
        if(h[i]>hm[i]) ans++;
    }
    cout<<ans<<"\n";
    return;
}
int32_t main() {
    io();
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}