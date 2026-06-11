#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int X;
    cin >> X;
    
    int N = X % 100;
    int cnt = 0;
    int j = 5;
    while (N > 0) {
        cnt += N / j;
        N %= j;
        --j;
    }
    if (X / 100 >= cnt) cout << 1 << endl;
    else cout << 0 << endl;
}

