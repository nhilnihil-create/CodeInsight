#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int num = N / 100;
    int r = N % 100;
    if (r > 5 * num) cout << 0 << endl;
    else cout << 1 << endl;
}
