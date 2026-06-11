#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
const int maxn = 105 + 5;
ll a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    int n ; cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    sort(a + 1 , a + 1 + n);
    ll ans = 1e18;
    for (int i = a[1] ; i <= a[n] ; i++){
        ll res = 0;
        for (int j = 1 ; j <= n ; j++){
            res += (a[j] - i) * (a[j] - i);
        }
        ans = min (ans , res);
    }
    cout << ans << endl;
    return 0;
}
