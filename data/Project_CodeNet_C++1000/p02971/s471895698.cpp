#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> a(n), v_front(n), v_back(n);
    for (size_t i = 0; i < n; i++) cin >> a[i];

    int m = 0;
    for (int i = 0; i < n; i++) {
        v_front[i] = m;
        m = max(m, a[i]);
    }

    m = 0;
    for (int i = n-1; i >= 0; i--) {
        v_back[i] = m;
        m = max(m, a[i]);
    }

    for (size_t i = 0; i < n; i++) {
        cout << max(v_front[i], v_back[i]) << endl;
    }
    return 0;
}
