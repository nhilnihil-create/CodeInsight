#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> t(n);
    rep(i, n) cin >> s[i] >> t[i];
    string x;
    cin >> x;
    int ans = 0;
    int num = 0;
    rep(i, n) {
        if(s[i] == x) num = i;
    }
    for(int i = num + 1; i < n; i++) {
        ans += t[i];
    }
    cout << ans << endl;
    return 0;
}