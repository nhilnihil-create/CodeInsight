#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    //cin >> t;
    for(int T = 0; T < t ; T++){
       ll n, ans = 0;
       cin >> n;
       ll a[n], b[n], cnt1[n] = {0}, cnt2[n] = {0};
       for(int i = 0; i < n; i++){
           cin >> a[i];
           b[i] = i - a[i];
           a[i] += i;
           if(b[i] >= 0)
                cnt1[b[i]]++;
           if(a[i] < n)
                cnt2[a[i]]++;
       }
       for(int i = 0; i < n; i++){
           ans += cnt1[i]*cnt2[i];
       }
       cout << ans << endl;
    }
    return 0;
}