#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int N = 2e5 + 5;
LL n, p, mod, mul = 1, pre[N], ans, sum;
string s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n >> p >> s;
    if(p == 2 || p == 5) {
        for(int i = 0; i < n; i++) if((s[i] - '0') % p == 0) ans += i+1;
        return cout << ans, 0;
    }   

    reverse(s.begin(), s.end());

    mul = 1, pre[0]++;
    for(int i = 0; i < n; i++) {
        sum += (s[i] - '0') * mul;
        sum %= p;
        pre[sum]++;
        mul = mul * 10 % p;
    }

    for(int i = 0; i < p; i++) ans += (pre[i] * (pre[i] - 1)) / 2;
    cout << ans;
}