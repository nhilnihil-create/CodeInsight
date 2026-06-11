#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N;

void solve() {
    cin >> N;
    N--;
    cout << (1 + N) * N / 2 << endl;
}

int main() {
    solve();
    return 0;
}

