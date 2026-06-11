#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n;
    ll ans = 0;
    cin >> n;
    vector<int> v(n+1, 1);
    for(int i = 2; i <= n; i++){
        for(int j = i; j <= n; j += i){
            v[j]++;
        }
    }
    for(int i = 1; i <= n; i++){
        ans += (ll)i * v[i];
    }
    cout << ans << endl;
    return 0;
}
