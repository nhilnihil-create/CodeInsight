#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ll long long
#define P pair<int,int>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD = 1000000007;
const int INF = 2002002002;
const ll LLINF = 9009009009009009009;
using namespace std;

int main() {
    fast_io
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int interval = 1; interval < n; interval++) {
        int ans_tmp = 0;
        for (int left = 0; left + interval < n; left++) {
            int right = left + interval;
            if (s[left] == s[right]) ans_tmp++;
            else ans_tmp = 0;
            ans = max(ans, min(ans_tmp, interval));
        }
    }
    cout << ans << endl;
    return 0;
}