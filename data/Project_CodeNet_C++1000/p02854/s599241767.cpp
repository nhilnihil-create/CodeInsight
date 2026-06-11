#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    ll a[n];
    long long sum = 0,x = 0,ans = 1000000000000000;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i < n; i++){
        x += a[i];
        sum -= a[i];
        ans = min(ans,abs(sum-x)); 
    }
    cout << ans << endl;

    return 0;
}
