#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    string S;
    int n;
    int m = 2019;

    cin >> S;

    n = S.size();
    reverse(S.begin(), S.end());
    int x = 1, tot = 0;
    vector<int> cnt(m);
    ll ans = 0;
    rep(i,n) {
        cnt[tot]++;
        tot += (S[i]-'0')*x;
        tot %= m;
        ans += cnt[tot];
        x = x*10%m;
    }

    cout << ans << endl;

    return 0;
    
}