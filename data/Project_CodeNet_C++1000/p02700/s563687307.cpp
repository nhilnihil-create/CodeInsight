#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    while (1) {
        if (C <= 0) {
            cout << "Yes" << endl;
            return 0;

        }
        if (A <= 0) {
            cout << "No" << endl;
            return 0;
        }
        C -= B;
        A -= D;
    }
    return 0;
}
