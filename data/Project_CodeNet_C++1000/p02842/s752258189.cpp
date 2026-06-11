#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int price = i * 1.08;
        if (price == N) {
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
}

