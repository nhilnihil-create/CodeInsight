#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    int ans = INT_MAX;
    for (int i = 0; i <= (int)(a.size()) - (int)(b.size()); ++i) {
        int d = 0;
        for (int j = 0; j < b.size(); ++j) {
            if (a[j + i] != b[j]) ++d;
        }
        ans = min(ans, d);
    }
    cout << ans << endl;
}
