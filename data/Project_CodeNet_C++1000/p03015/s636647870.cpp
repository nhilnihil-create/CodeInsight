#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int mod = 1e9 + 7;
char s[100005];

LL power(LL x, LL y) { 
    int res = 1;
    x = x % mod;
    while (y > 0) { 
        if (y & 1) res = (res * x) % mod; 
        y = y >> 1;
        x = x * x % mod; 
    } 
    return res; 
} 

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> s + 1; int n = strlen(s + 1), cnt = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] == '1') {
            (ans += power(2LL, cnt) * power(3LL, n - i) % mod) %= mod;
            cnt++;
        }
    }    
    (ans += power(2LL, cnt)) %= mod;
    cout << ans;    
}