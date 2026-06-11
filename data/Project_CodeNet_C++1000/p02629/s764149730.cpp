#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back
#define vi vector<int>

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    string ans = "";

    while(n > 0) {
        n--;
        ans += ('a' + ((n)%26));
        n /= 26;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}

