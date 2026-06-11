#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N, P;
string S;
int cnt[10010];

int mod_pow(int x, int n, int mod) {
    int res = 1;
    
    while (n>0) {
        if (n&1) res = res*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    
    return res;
}


signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> P >> S;
    if (P==2) {
        int ans = 0;
        rep(i, N) if ((S[i]-'0')%2==0) ans += i+1;
        cout << ans << endl;
        exit(0);
    }
    if (P==5) {
        int ans = 0;
        rep(i, N) if (S[i]=='0' || S[i]=='5') ans += i+1;
        cout << ans << endl;
        exit(0);
    }
    
    reverse(S.begin(), S.end());
    cnt[0] = 1;
    int now = 0;
    int ans = 0;
    rep(i, N) {
        now += (S[i]-'0')*mod_pow(10, i, P);
        now %= P;
        ans += cnt[now];
        cnt[now]++;
    }
    cout << ans << endl;
}