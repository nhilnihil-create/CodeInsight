#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    int result = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != s[n - 1 - i])
            result++;
    }
    cout << result / 2 << "\n";
    return 0;
}
