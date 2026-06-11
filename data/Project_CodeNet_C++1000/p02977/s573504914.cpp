#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N; cin >> N;
    if (__builtin_popcount(N) != 1) {
        cout << "Yes\n";
        for (int i = 2; i+1 <= N; i += 2) {
            cout << i << ' ' << i+1 << '\n';
            cout << i+1 << ' ' << 1 << '\n';
            cout << 1 << ' ' << N+i << '\n';
            cout << N+i << ' ' << N+i+1 << '\n';
            if (i == 2) cout << N+i+1 << ' ' << N+1 << '\n';
        }
        if (N % 2 == 0) {
            cout << N << ' ' << N+N-2 << '\n';
            cout << (N^(N-2)^1) << ' ' << N+N << '\n';
        }
    } else {
        cout << "No\n";
    }
    return 0;
}
