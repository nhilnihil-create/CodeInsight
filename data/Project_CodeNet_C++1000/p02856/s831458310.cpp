#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

signed main(){
    int m; cin >> m;
    string s;
    int sum = 0, digit = 0;
    for(int i = 0; i < m; i++){
        int d, c; cin >> d >> c;
        digit += c;
        sum += d * c;
    }
    int ans = (sum - 1)/9 + digit - 1;
    cout << ans << endl;
}