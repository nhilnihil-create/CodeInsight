#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353
#define Graph vector<vector<int>>

void dfs(int k, ll now, vector<ll> &ans) {
    ans.push_back(now);
    if(k == 10) return;
    for(int u = -1; u <= 1; u++) {
        int add = (now % 10) + u;
        if(add >= 0 && add <= 9) dfs(k + 1, now * 10 + add, ans);
    }
}

int main() {
    int K; cin >> K;
    vector<ll> ans;
    for (int i = 1; i <= 9; i++) dfs(1, i, ans);
    sort(ans.begin(), ans.end());
    cout << ans.at(K - 1) << endl;
}