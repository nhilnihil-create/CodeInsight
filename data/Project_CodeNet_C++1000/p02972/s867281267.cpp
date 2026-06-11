#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1), b, temp_res(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        int contained = 0, k = 1;
        while (k * i <= n) {
            contained += temp_res[k*i];
            k++;
        }
        if (contained % 2 != a[i]) {
            b.push_back(i);
            temp_res[i] = 1;
        }
    }
    cout << b.size() << endl;
    for (auto x : b) {
        cout << x << " ";
    }
    cout << endl;
}