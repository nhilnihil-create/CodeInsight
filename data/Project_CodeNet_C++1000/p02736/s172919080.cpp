#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    string s; cin >> s;
    bool f = true;
    vector<int> a(N); for (int i = 0; i < N; i++) {
        a[i] = s[i]-'0' - 1;
        if (a[i] == 1) f = false;
    }
    if (f) for (int i = 0; i < N; i++) a[i] /= 2;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + (N-1 == (i | (N - 1 - i))) * a[i] ) % 2;
    }
    if (ans == 1) {
        if (f) {
            cout << 2 << endl;
        } else {
            cout << 1 << endl;
        }
    } else {
        cout << 0 << endl;
    }
}
