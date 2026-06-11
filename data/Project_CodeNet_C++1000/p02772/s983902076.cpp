#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    int *a = new int[n + 5];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string s = "APPROVED";
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            if ((a[i] % 3 != 0) && (a[i] % 5 != 0)) {
                s = "DENIED";
            }
        }
    }
    cout << s << endl;
    return 0;
}