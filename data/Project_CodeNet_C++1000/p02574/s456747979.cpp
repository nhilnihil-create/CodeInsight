#include <iostream>
#include <cmath>
#include <vector>
#include <set>

#define N 1000000

typedef long long ll;

using namespace std;

int prime[N + 1];
int D[N + 1];
int used[N + 1];

int main() {
    for (int i = 0; i <= N; ++i) {
        prime[i] = 1;
        D[i] = i;
        used[i] = 0;
    }
    prime[0] = prime[1] = 0;

    int p = 2;
    while (p < sqrt(N)) {
        for (int i = p * 2; i <= N; i += p) {
            prime[i] = 0;
            D[i] = p;
        }

        for (int i = p + 1; i <= N; ++i) {
            if (prime[i] == 1) {
                p = i;
                break;
            }
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int A;
        cin >> A;

        set<int> s;
        while (A != D[A]) {
            s.insert(D[A]);
            A = A / D[A];
        }
        s.insert(A);
        for (auto it = s.begin(); it != s.end(); ++it) {
            ++used[*it];
        }
    }

    bool pairwise = true;
    bool setwise = true;

    for (int i = 2; i <= N; ++i) {
        if (used[i] >= 2) {
            pairwise = false;
        }
        if (used[i] >= n) {
            setwise = false;
        }
    }

    if (pairwise) {
        cout << "pairwise coprime" << endl;
    }
    else if (setwise) {
        cout << "setwise coprime" << endl;
    }
    else {
        cout << "not coprime" << endl;
    }

    return 0;
}