#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

signed main(){
    int N; cin >> N;
    vector<int> a(N), sum(N, 0);
    for(int i = 0; i < N; i++) cin >> a[i];
    int ans = 3;
    sum[0] = 1;
    if(a[0] != 0){
      cout << 0 << endl;
      return 0;
    }
    for(int i = 1; i < N; i++){
        if(a[i] != 0) ans *= (sum[a[i] - 1] - sum[a[i]]);
        if(a[i] == 0) ans *= (3 - sum[a[i]]);
        ans %= mod;
        sum[a[i]]++;
    }
    cout << ans << endl;
}
