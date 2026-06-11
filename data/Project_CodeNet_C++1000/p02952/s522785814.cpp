#include <bits/stdc++.h>

#define tc(t) int t; cin>>t; while(t--)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    string s;
    for (int i = 1; i <= n; ++i) {
        s = to_string(i);
        if (s.length() % 2 != 0) cnt++;
    }
    cout << cnt << endl;

}




