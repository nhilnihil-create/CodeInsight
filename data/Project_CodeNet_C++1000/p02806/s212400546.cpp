#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<tuple<string, int> > vt;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        string s;
        int a;
        cin >> s >> a;
        vt.emplace_back(s, a);
        ans += a;
    }

    string X;
    cin >> X;
    for (int i = 0; i < N; ++i) {
        ans -= get<1>(vt[i]);
        if (get<0>(vt[i]) == X) break;
    }
    cout << ans << endl;
}
