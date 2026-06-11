#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int long long
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repr(i, a, b) for(int i = a - 1; i >= b; i--)
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)
#define iterr(m) for(auto it = m.rbegin(); it != m.rend(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
const ll mod = (ll)1e9 + 7;
int quickPow(int x, int n) {
    int res = 1;
    while(n > 1) {
        if(n % 2 == 0) {
            n >>= 1;
            x *= x;
        } else {
            n--;
            res *= x;
        }
        res %= mod;
        x %= mod;
    }
    return (res * x) % mod;
}
int inverse(int x) {
    return quickPow(x, mod - 2);
}
int CK(int n, int k) {
    int ans = 1;
    int sub = 1;
    for(int i = 0; i < k; i++) ans = ans * (n - i) % mod;
    for(int i = 1; i <= k; i++) sub = sub * i % mod;
    
    return ans * inverse(sub) % mod;
}
signed main(){
    speed;
    int n, a, b; cin >> n >> a >> b;
    int ans = quickPow(2, n) - 1;
    ans = (ans - (CK(n, a) + CK(n, b))) % mod;
    cout << (ans + mod) % mod;
    return 0;
}