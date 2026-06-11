#include <bits/stdc++.h>
using namespace std;

int main(){
    int k, q;
    int64_t d[5000], sum[5001];
    cin >> k >> q;
    for(int i=0;i<k;++i) cin >> d[i];
    while(q--){
        int64_t n, x, m;
        cin >> n >> x >> m;
        sum[0] = 0;
        for(int i=1;i<=k;++i) sum[i] = sum[i-1] + (d[i-1] + m - 1) % m + 1;
        int64_t ans = (n - 1) - (x % m + sum[k] * ((n - 1) / k) + sum[(n - 1) % k]) / m;
        cout << ans << endl;
    }
    return 0;
}