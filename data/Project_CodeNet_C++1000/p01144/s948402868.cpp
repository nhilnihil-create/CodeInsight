#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef pair<int, int> P;

signed main(){
    int d, e;
    while(1){
        int n, m;
        cin >> n >> m;
        if(n + m == 0) break;
        vector<P> data;
        rep(i, 0, n){
            int d, p;
            cin >> d >> p;
            data. push_back(P(p, d));
        }
        sort(all(data));
        reverse(all(data));
        int ans = 0;
        rep(i, 0, n){
            if(data[i].second <= m){
                m -= data[i].second;
            }else if(m == 0){
                ans += data[i].first * data[i].second;
            }else{
                ans += data[i].first * (data[i].second - m);
                m = 0;
            }
        }
        cout << ans << endl;
    }
}