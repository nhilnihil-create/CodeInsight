#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s, t;
    int count = 0;
    cin >> s >> t;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == t[i]) {
            count++;
        }
    }
    cout << count;

    return 0;
}

