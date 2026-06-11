#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1000000007;

int N, A[1<<18], C[3];
ll sum = 1;

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++) {
        ll cnt = 0, id = -1;
        if (A[i] == C[0]) { cnt++; id = 0; }
        if (A[i] == C[1]) { cnt++; id = 1; }
        if (A[i] == C[2]) { cnt++; id = 2; }
        if (id == -1) {
            cout << "0" << endl;
            return 0;
        }

        sum *= cnt; C[id]++;
        sum %= mod;
    }
    cout << sum << endl;
}
