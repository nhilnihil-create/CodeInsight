#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(std::string T) {
    rep(i, T.size()) {
        if (T[i] == '?') {
            T[i] = 'D';
        }
    }
    cout << T << endl;
}

int main() {
    std::string T;
    std::cin >> T;
    solve(T);
    return 0;
}
