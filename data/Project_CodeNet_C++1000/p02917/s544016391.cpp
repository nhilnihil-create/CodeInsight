#include <bits/stdc++.h>
using namespace std;

int n;
int b[110];
int sum = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        cin >> b[i];
    }
    sum += b[0];
    for (int i = 1; i < n-1; ++i) {
        sum += min(b[i], b[i-1]);
    }
    sum += b[n-2];
    cout << sum << "\n";
    return 0;
}
