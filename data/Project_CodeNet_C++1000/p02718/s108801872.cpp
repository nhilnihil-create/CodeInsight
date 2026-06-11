#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    vector<int> A(n);
    for (size_t i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i];
    }

    int ans = 0;
    for (size_t i = 0; i < n; i++) {
        if (A[i] >= (double)sum/(4*m)) ++ans;
    }
    if (ans >= m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
