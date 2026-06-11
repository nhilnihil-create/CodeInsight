#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define endl "\n"
typedef long long ll;

const int BIG_NUM = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
