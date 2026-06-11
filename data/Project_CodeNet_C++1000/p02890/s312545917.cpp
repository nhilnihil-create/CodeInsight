#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


int main() {
    ll n;
    cin >> n;
    vector<ll> cnt(330000, 0), cntcnt(330000, 0), ans(330000, 0);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        cnt[a]++;
    }
    int kind = 0;
    for(int i = 1; i <= n; i++){
        cntcnt[cnt[i]]++;
        if(cnt[i] > 0) kind++;
    }
    int sum = 0;
    for(int i = 1; i <= n; ++i){
        kind -= cntcnt[i];
        sum += cntcnt[i]*i;
        ll maxk = (sum + kind*i)/i;
        ans[maxk] = i;
    }
    for(int i = n-1; i > 0; i--){
        ans[i] = max(ans[i+1], ans[i]);
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << endl;
    }
}
