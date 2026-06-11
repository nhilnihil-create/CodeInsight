#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define endl '\n'
#define ll long long
const int N = 2e5 + 5;
pair<ll,ll> b[N];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if (fopen(".INP", "r")){
                freopen(".INP", "r", stdin);
                freopen(".OUT", "w", stdout);
        }
        ll n, d, a;
        cin >> n >> d >> a;
        for (int i = 1; i <= n; i++){
                cin >> b[i].first >> b[i].second;
        }
        sort(b + 1, b + n + 1);
        set<pair<ll,ll>> s;
        ll cnt = 0, ans = 0;
        for (int i = 1; i <= n; i++){
                while (s.size() > 0) {
                      if ((*s.begin()).first < b[i].first){
                            cnt -= (*s.begin()).second;
                            s.erase(s.begin());
                      } else {
                            break;
                      }
                }
                if (cnt >= b[i].second) continue;
                ll x = (b[i].second - cnt) / a;
                if (((b[i].second - cnt )% a) != 0) x++;
                cnt += a * x;
                ans += x;
                s.insert({b[i].first + d * 2, a * x});
        }
        cout << ans;
}
