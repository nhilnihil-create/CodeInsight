#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define all(a) a.begin(), a.end()
#define sz(a) a.size()
using namespace std;

ll n, a[200001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("A.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int nn=n-2;
    ll ans = a[n-1];
    for(int i=n-2; i>=0; i--){
        if(nn--) ans += a[i];
        else break;
        if(nn--) ans += a[i];
        else break;
    }
    cout << ans << endl;
}
