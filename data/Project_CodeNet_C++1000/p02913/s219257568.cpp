#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
const int b1 = 37 , b2 = 31;
const int mod = 1e9 + 7;
int n;
int pw1[N] , inv1[N];
int pw2[N] , inv2[N];
int pref1[N] , pref2[N];
string s;
int fp(int x , int y) {
    if(!y)
        return 1;
    int res = fp(x , y / 2);
    res = (1ll * res * res) % mod;
    if(y & 1)
        res = (1ll * res * x) % mod;
    return res;
}
void pre() {
    pw1[0] = inv1[0] = 1;
    pw2[0] = inv2[0] = 1;
    int minv1 = fp(b1 , mod - 2);
    int minv2 = fp(b2 , mod - 2);
    for(int i = 1;i < N;i++) {
        pw1[i] = (1ll * b1 * pw1[i - 1]) % mod;
        pw2[i] = (1ll * b2 * pw2[i - 1]) % mod;
        inv1[i] = (1ll * minv1 * inv1[i - 1]) % mod;
        inv2[i] = (1ll * minv2 * inv2[i - 1]) % mod;
    }
}
pair<int , int> get(int l , int r) {
    int ans1 = pref1[r] , ans2 = pref2[r];
    if(l) {
        ans1 = (ans1 - pref1[l - 1] + mod) % mod;
        ans2 = (ans2 - pref2[l - 1] + mod) % mod;
    }
    ans1 = (1ll * ans1 * inv1[l]) % mod;
    ans2 = (1ll * ans2 * inv2[l]) % mod;
    return {ans1 , ans2};
}
int main() {
    abdelrahman010
    cin >> n >> s;
    pre();
    for(int i = 0;i < n;i++) {
        int c = s[i] - 'a' + 1;
        pref1[i] = (1ll * c * pw1[i]) % mod;
        pref2[i] = (1ll * c * pw2[i]) % mod;
        if(i) {
            pref1[i] = (pref1[i] + pref1[i - 1]) % mod;
            pref2[i] = (pref2[i] + pref2[i - 1]) % mod;
        }
    }
    int low = 1 , high = n / 2 , mid , ans = 0;
    while(low <= high) {
        mid = low + high >> 1;
        bool yes = false;
        for(int i = 0;i + mid <= n && !yes;i++) {
            for(int j = i + mid;j + mid <= n;j++)
                if(get(i , i + mid - 1) == get(j , j + mid - 1)) {
                    yes = true;
                    break;
                }
        }
        if(yes)
            ans = mid , low = mid + 1;
        else
            high = mid - 1;
    }
    cout << ans;
    return 0;
}