#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    s.erase(unique(s.begin(), s.end()), s.end());
    cout << s.size() << endl;

    return 0;
}