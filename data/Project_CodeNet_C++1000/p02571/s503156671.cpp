#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };
const int LIT = -32768 * 100;

int n, m;
int arr[101];

void solve() {
    string s, t;
    cin >> s >> t;
    int ans = 1001;

    if (s.length() == t.length()) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] != t[i]) cnt++;
        cout << cnt;
    }
    else {
        for (int i = 0; i < s.length() - t.length(); i++) {
            int cnt = 0;
            for (int j = 0; j < t.length(); j++) {
                if (s[i + j] != t[j])  cnt++;
            }
            ans = min(ans, cnt);

        }
        cout << ans;
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
