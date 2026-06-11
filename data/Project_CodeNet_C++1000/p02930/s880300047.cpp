#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    for ( int i = 1; i < N; i++ ) {
        for ( int j = i+1; j <= N; j++ ) {
            cout << __builtin_ffs(i^j) << " ";
        }
        cout << "\n";
    }
    return 0;
}