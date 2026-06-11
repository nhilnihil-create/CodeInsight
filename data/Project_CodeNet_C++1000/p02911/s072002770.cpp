#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> point(n, k-q);

    for (size_t i = 0; i < q; i++) {
        int a;
        cin >> a;
        point[a-1] += 1;
    }

    for (size_t i = 0; i < n; i++) {
        if (point[i] > 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
