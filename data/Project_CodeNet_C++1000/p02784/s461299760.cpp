#include <bits/stdc++.h>
using namespace std;
#define hyperspeed ios::sync_with_stdio(false);cin.tie(NULL);
#define ll long long  
#define ull unsigned long long
#define ui unsigned int
#define li long int
#define uli unsigned long int
#define pb push_back
#define ld long double
#define vi vector<int>
#define vvi vector<vector<int>>
#define vli vector<li>
#define vll vector<ll>
#define all(v) v.begin(),v.end()
#define pi pair<int,int>
#define FOR(i,s,n) for(auto i=s;i<n;++i)
#define FORN(i,s,n) for(auto i=s;i<=n;++i)
#define FORR(i,s,n) for(auto i=s;i>=n;--i)
#define FORE(i,a) for(auto i : a)
#define mp make_pair
const int MOD = 1e9+7;

void solve() {
    ll h;
    ll n;
    ll sum = 0;
    cin >> h >> n;
    FOR(i,0,n) {
        ll x;
        cin >> x;
        sum+=x;
    }
    if(sum>=h) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}

int32_t main()
{
    hyperspeed
    int test=1;
    // cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}

//--n1m5
