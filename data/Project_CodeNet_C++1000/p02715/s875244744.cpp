#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define For(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(),(x).end()
typedef long long lint;
typedef vector<long long> vlint;
typedef vector<string> vstr;
typedef vector<char> vchar;
typedef vector<vector<long long>> vlint2;

lint powmod(lint a, lint b, lint mod = 1000000007) {
   lint res = 1;
   for (a %= mod; b; a = a * a % mod, b >>= 1)
     if (b & 1) res = res * a % mod;
   return res;
}


int main() {
    int mod = 1000000007;
    int n, k; cin >> n >> k;
    lint cnt[k+10];

    for (int x = k; x > 0; x--){
        cnt[x] = powmod(k/x, n);
        for (int y = 2 * x; y <= k; y+=x){
            cnt[x] -= cnt[y];
        }
    }
    lint ans = 0;
    For(i, 1, k+1){
        ans += (i * cnt[i]) % mod;
        ans %= mod;
    }
    cout << ans << endl;
}

