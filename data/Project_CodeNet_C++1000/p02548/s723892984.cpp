#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int main() { 
    ll N, B, C, cnt=0;
    cin >> N;
    for(int A = 1; A <= N; ++A) {
        // cout << A << " : ";
        if (N % A == 0) {
            B = (N / A) - 1;
            // cout << B << endl;
            cnt += B;
        } else {
            B = N / A;
            // cout << B << endl;
            cnt += B;
        }
    }

    cout << cnt <<"\n";
    return 0;
}
