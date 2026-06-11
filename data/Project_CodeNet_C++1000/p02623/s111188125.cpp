#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n+1), b(m+1);
    for(int i = 1; i <= n; i++){
        int ai;
        cin >> ai;
        a[i] = a[i-1] + ai;
    }
    for(int i = 1; i <= m; i++){
        int bi;
        cin >> bi;
        b[i] = b[i-1] + bi;
    }

    int ans = 0;
    for(int i = 0; i <= n; i++){
        if(a[i] > k) break;
        int ng = -1;
        int ok = (int)b.size();

        while(abs(ok-ng) > 1){
            int mid = (ok + ng)/2;
            if(b[mid] > k - a[i]) ok = mid;
            else ng = mid;
        }
        ans = max(ans, i + ok - 1);
    }
    cout << ans << endl;
}