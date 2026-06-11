#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, p; cin >> n >> p;
    string s; cin >> s;
    ll ans = 0;
    if(p == 2 || p == 5){
        for(int i = 0; i < n; i++) if((s[n-i-1]-'0') % p == 0) ans += n-i;
        cout << ans << endl;
        return 0;
    }
    vector<ll> cnt(p,0);
    int k = 1;
    int now = 0;
    cnt[now]++;
    for(int i = 0; i < n; i++){
        now = (now + (s[n-i-1] - '0')*k) % p;
        k = (k * 10) % p;
        cnt[now]++;
    }
    rep(i,p) ans += cnt[i] * (cnt[i] - 1) / 2;
    cout << ans << endl;
    return 0;
}