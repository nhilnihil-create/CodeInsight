#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    for(int i = 0; i < n; i++) {
        cout << s[i] << t[i];
    }

    return 0;
}
