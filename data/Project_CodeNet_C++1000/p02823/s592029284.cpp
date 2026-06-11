#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long N, A, B;
    cin >> N >> A >> B;

    if ((B - A) % 2 == 0) {
        cout << (B - A) / 2 << endl;
        return;
    }

    long long AtoLast = N - A;
    long long BtoTop = B - 1;

    if (AtoLast < BtoTop) {
        // A will move to Last
        long long BtoLast = N - B;
        long long ans = (BtoLast + 1) + (N - (A + BtoLast + 1)) / 2;
        cout << ans << endl;
    }
    else {
        // B will move to Top
        long long AtoTop = A - 1;
        long long ans = (AtoTop + 1) + (B - (AtoTop + 1) - 1) / 2;
        cout << ans << endl;
    }
    return;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
