#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define endl "\n"
typedef long long ll;

const int BIG_NUM = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    for(int i = 0; i < 3; i++) {
        if(s[i] == s[i + 1]) {
            cout << "Bad";
            return 0;
        }
    }
    cout << "Good";
    return 0;
}
