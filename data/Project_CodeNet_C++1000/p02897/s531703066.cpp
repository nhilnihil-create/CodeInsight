#include <bits/stdc++.h>
using namespace std;

int N;

void solve() {
    cin >> N;
    cout.precision(10);
    cout << (double)(N - N / 2) / (double)N << endl;
    return;
}

int main() {
    solve();
    return 0;
}
