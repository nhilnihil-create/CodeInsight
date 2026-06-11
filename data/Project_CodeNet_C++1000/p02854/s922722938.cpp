#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<ll> sum(n + 1,0),a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }
    ll ans = 1145141919810364;
    for(int i = 0; i < n; i++){
        ans = min(ans, abs(sum[i + 1] - (sum[n] - sum[i + 1])));
    }
    cout << ans << endl;
}