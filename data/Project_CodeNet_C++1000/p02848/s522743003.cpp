#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        int x = s[i] - 'A';
        x = (x + n) % 26;
        char c = x + 'A';
        cout << c;
    }
    cout << "\n";
    return 0;
}
