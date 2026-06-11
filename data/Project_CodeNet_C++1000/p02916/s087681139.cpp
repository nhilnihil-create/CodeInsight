#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXX 1005
#define PI 3.14159265358979323846264338327950
#define ll signed long long int
using namespace std;
ll t , n, k,  x = 0, y = 2, m, ans = 0 ;
ll a[MAXX], b[MAXX], c[MAXX], d;
double f = 0.5;
vector<ll> v[MAXX];
bool used[MAXX];

signed main()
{
	
	cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        ans += b[i];
    }
    for(int i = 1; i <= n - 1; i++){
        cin >> c[i];
    }
    for(int i = 2; i <= n; i++){
        if(a[i] == (a[i - 1] + 1))
            ans += c[a[i - 1]];
    }
    cout << ans << endl;
	return 0;    
}