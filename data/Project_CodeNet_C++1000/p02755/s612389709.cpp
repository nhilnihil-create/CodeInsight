#include <bits/stdc++.h>
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
using namespace std;

int main() {
    int A, B; cin >> A >> B;

    int nf = -1;
    for (int i = 1; i <= 10000; i++) {
        if ((int)(i * 0.08) == A && (int)(i * 0.1) == B) {
            cout << i << endl;
            return 0;
        }
    }
    cout << nf << endl;
}