#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int N;
    cin >> N;
    ll a[N];
    ll t = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        t = (t ^ a[i]);
    }
    for (int i = 0; i < N; i++) {
        if (i == N - 1) {
            cout << (t ^ a[i]) << "\n";
        } else {
            cout << (t ^ a[i]) << " ";
        }
    }
    return 0;
}