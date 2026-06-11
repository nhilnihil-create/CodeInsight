#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, A, B;
    cin >> N >> A >> B;

    if (A == 0) {
        cout << 0 << endl;
    }
    else {
        long long count = N / (A + B);
        long long remain = N % (A + B);

        long long ans = A * count;
        if (remain >= A) {
            ans += A;
        }
        else {
            ans += remain;
        }
        cout << ans << endl;
    }
    return 0;
}