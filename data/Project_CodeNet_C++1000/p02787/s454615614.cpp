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
        ll n, h;
        cin >> h >> n;
        vector<pair <ll ,ll>>  p(n);
        for(int i = 0 ; i < n ; i++){
            cin >> p[i].first >> p[i].second;
        }
        sort(p.begin(), p.end());
        ll ans[h + 1];
        for(int i = 0; i <= h; i++)
            ans[i] = 1e9;
        ans[0] = 0;
        for(int i = 1; i <= h; i++){
            for(int j = 0; j < n; j++){
                ans[i] = min(ans[i], ans[max(i - p[j].first,0LL)] + p[j].second);   
            }
            if(ans[i] == 1e9){
                ans[i] = p[0].second;
            }
        }
        cout << ans[h] << endl;
    }
    return 0;
}