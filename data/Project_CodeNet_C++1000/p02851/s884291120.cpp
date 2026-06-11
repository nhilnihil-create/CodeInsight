#include <bits/stdc++.h>

using namespace std;


using i64 = long long;

signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i){
        --a[i];
        a[i] %= k;
    }
    vector<int> r(n + 1, 0);
    for(int i = 0; i < n; ++i)
        r[i + 1] = (r[i] + a[i]) % k;
    map<int,int>v ;
    i64 ans = 0;
    for(int i = 0; i <= n; ++i){
        ans += v[r[i]];
        v[r[i]]++;
        if(i - k + 1 >= 0)
            v[r[i - k + 1]]--;
    }
    cout << ans << endl;
}
