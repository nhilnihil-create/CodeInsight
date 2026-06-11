#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> s(N);
    vector<int> t(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i] >> t[i];
    }

    string X;
    cin >> X;

    int ans = 0;
    bool sleep = false;
    for (int i = 0; i < N; i++) {
        if (sleep) {
            ans += t[i];
        }
        if (s[i] == X) {
            sleep = true;
        }
    }
    cout << ans << endl;
}
