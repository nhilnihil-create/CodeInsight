#include<bits/stdc++.h>
#define EM 1000000
using namespace std;
using LL = long long;
using P = pair<LL, LL>;
LL LINF = 1e18;
int INF = 1e9;
LL mod = 1e9+7;
using vint = vector<int>;
using vLL = vector<LL>;
using vvint = vector<vector<int>>;
using vvLL = vector<vector<LL>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    LL N;
    LL K;
    cin >> N >> K;
    vector<LL> a(N);
    for(int i = 0;i < N;i++) {
        cin >> a[i];
        a[i] = a[i]%K - 1;
    }
    vector<LL> modsum(N);
    LL sum = 0;
    for(int i = 0;i < N;i++) {
        sum += a[i];
        modsum[i] = sum % K;
    }
    map<LL, LL> mp;
    LL ans = 0;
    for(int i = 0;i < min(K, N);i++) {
        mp[modsum[i]] = mp[modsum[i]] + 1;
        if(i+1 == K && modsum[i] == 0)  ans--;
    }
    for(auto& m : mp) {
        LL key = m.first;
        LL value = m.second;
        ans += value * (value - 1) / 2;
        if (key == 0) {
            ans += value;
        }
    }
    for(int i = 1;i + K - 1 < N;i++) {
        mp[modsum[i-1]] = mp[modsum[i-1]] - 1;
        mp[modsum[i+K-1]] = mp[modsum[i+K-1]] + 1;
        ans += mp[modsum[i+K-1]] - 1;
    }
    cout << ans << endl;
}