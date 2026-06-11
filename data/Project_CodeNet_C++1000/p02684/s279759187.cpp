#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    vector<long long> teleport(n,0);
    for (long long i = 0; i < n; i++) {
        long long a;
        cin >> a;
        teleport[i] = a;
    }
    int i = teleport[0];
    vector<bool> visited(n,false);
    visited[0] = true;
    k--;
    int cycle = 0;
    int start = 0;
    while (k > 0 && start != i) {
        if (visited[i-1]) {
            if (start == 0) {
                start = i;
            } else {
                cycle++;
            }
        }
        visited[i-1] = true;
        i = teleport[i-1];
        k--;
    }
    if (k > 0) {
        k = k % (cycle + 1);
    }
    while (k > 0) {
        i = teleport[i-1];
        k--;
    }
    cout << i;
}
