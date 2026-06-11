#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define all(a) a.begin(), a.end()
#define sz(a) a.size()
#define pb push_back
using namespace std;

const ll mod = 1e9+7;

ll n, d[10000001], ans=0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("A.txt", "r", stdin);
    #endif
    cin >> n;
    for(int i=1; i<=n; i++){
        ll x = n/i;
        ans += x*(i+n-n%i)/2;
    }
    cout << ans;
}
