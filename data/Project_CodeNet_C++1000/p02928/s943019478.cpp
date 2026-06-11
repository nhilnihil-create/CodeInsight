#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;

// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
    ll n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int x=0; //初項
    int y=0; //交差
    rep(i,n){
        rep(j,n){
            if(i==j) continue;
            if(a[i]<a[j]){
                y++;
                if(i>j)
                    x++;
            }
        }
    }
    ll sum = (k-1)*y;
    sum+=2*x;
    sum%=MOD;
    sum*=k;
    sum%=MOD;
    sum = sum* modinv(2, MOD) % MOD;
    cout << sum << endl;
}