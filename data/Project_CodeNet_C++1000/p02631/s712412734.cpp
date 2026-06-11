#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<bitset<32>> a(n);
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        a[i] = b;
    }
    bitset<32> det(0);
    for (int i = 0; i < n; i++) {
        det ^= a[i];
    }
    for (int i = 0; i < 32; i++) {
        if (det.test(i)) {
            for (int j = 0; j < n; j++) {
                a[j].flip(i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i].to_ulong();
        if (i != n - 1)
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}
