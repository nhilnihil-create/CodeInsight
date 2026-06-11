#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, sum = 0;
    cin >> n;
    int b[n - 1];
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    sum += b[0];
    sum += b[n - 2];
    for (int i = 0; i < n - 2; i++) {
        sum += min(b[i], b[i + 1]);
    }
    cout << sum;
}

