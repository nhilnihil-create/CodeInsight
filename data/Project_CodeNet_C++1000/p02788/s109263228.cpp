#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define fast                                                                   \
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define fo(i,a,n) for (i = a; i <= n; i++)
#define F first
#define S second
#define pii pair<int,int>
#define sz size()
#define all(v) v.begin(),v.end()
#define pb push_back
#define pf push_front    
#define PB pop_back
#define pll pair<long long, long long>
#define vi vector<int>
#define vl vector<int>
#define mp make_pair
#define mod 1000000007
typedef unsigned long long ull;
const int N = 200005;
const int MOD = 998244353 ;


void solve(){
    int n, d, a, j = 0, ans = 0;
    cin>>n>>d>>a;
    vector<pair<int,int> > v;
    int c[n+10] = {0};
    f(i,n){
        int x, y;
        cin>>x>>y;
        v.pb(mp(x,y));
    }
    sort(all(v));
    f(i,n){
        while(j < n && v[j].F <= v[i].F + 2*d)j++;
        int cnt = max((v[i].S - c[i]*a + a - 1) / a, 0ll);
        c[i] += cnt;
        c[j] -= cnt;    
        ans += cnt;
        c[i+1] += c[i];
    }
    cout<<ans;
}

int32_t main() {
    fast
    int t;
    t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
