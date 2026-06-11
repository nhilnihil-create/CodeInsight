#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(i % 2 == 0) {
            if(s[i] == 'L') {
                cout << "No";
                return 0;
            }
        } else {
            if(s[i] == 'R') {
                cout << "No";
                return 0;
            }
        }

    }
    cout << "Yes";
    cout << "\n";
    return 0;
}
