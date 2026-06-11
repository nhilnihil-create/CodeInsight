#include<bits/stdc++.h>
#include<string>
#include<cmath>

using namespace std;

#define ll long long int
#define ld long double
#define loop(i, n) for (int i = 0; i < n; i++)
#define loops(i, s, n) for (int i = s; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define deb(x) cout<< #x << '=' << x <<endl
#define MOD 1000000007
const int N = 2e5 + 5;
vector<int> adj[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    ll ans = 0;
    for(int i = 0; i<n; i++){
        ans += (i + 1)*(n - i);
    }
    for(int i = 0; i<n-1; i++){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        ll l = min(u,v);
        ll r = max(u,v);
        ans -= (l + 1)*(n - r);
    }
    cout<<ans;
}