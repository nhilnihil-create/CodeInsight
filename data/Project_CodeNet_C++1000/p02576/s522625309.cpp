#include <iostream>

using namespace std;

int main(void)
{
    int N, X, T;

    cin >> N >> X >> T;

    int m = N / X;
    int n = N % X;
    int ans = m * T;

    if (n != 0) {
        ans += T;
    }

    cout << ans << endl;

    return 0;
}