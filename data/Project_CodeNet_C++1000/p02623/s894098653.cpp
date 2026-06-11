#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main(void){

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n+1), b(m+1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) cin >> b[i];
    for(int i = 1; i <= n; ++i) a[i] += a[i-1];
    for(int i = 1; i <= m; ++i) b[i] += b[i-1];

    int ans = 0;
    for(int i = 0; i <= n && k - a[i] >= 0; ++i){
        int ng = -1, ok = b.size(), mid = 0;
        while (abs(ok - ng) > 1) {
            mid = (ok + ng) / 2;

            if (k - a[i] < b[mid]) ok = mid;
            else ng = mid;
        }
        ans = max(ans, i + ok - 1);
    }

    cout << ans << "\n";

    return 0;
}
