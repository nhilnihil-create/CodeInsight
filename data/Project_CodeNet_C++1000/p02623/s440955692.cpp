#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define all(a) a.begin(), a.end()
#define sz(a) a.size()
#define pb push_back
using namespace std;

const ll mod = 1e9+7;

ll n, m, k, a[200001], b[200001], ans, x, c, d;
bool ok = 1;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("A.txt", "r", stdin);
    #endif
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(ok&&x+a[i]<=k){
            x += a[i];
            c++;
        }
        else ok=0;
    }
    ok=1;
    for(int i=0; i<m; i++){
        cin >> b[i];
        if(ok&&x+b[i]<=k){
            x += b[i];
            d++;
        }
        else ok=0;
    }
    ans = c+d;
    for(int i=c-1; i>=0; i--){
        x -= a[i];
        while(d<m&&x+b[d]<=k){
            x += b[d];
            d++;
        }
        ans = max(ans, i+d);
    }
    cout << ans;
}
