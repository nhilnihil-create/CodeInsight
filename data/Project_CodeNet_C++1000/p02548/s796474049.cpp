#include <iostream>

using namespace std;
typedef long long ll;

int main(void)
{
    int N;

    cin >> N;
    ll ans = 0;
    int t = 0;
    for (int A = 1; A <= N; A++) {
        for (int B = 1; B <= N / A; B++) {
            int C = N - A * B;
            if (C > 0) {
                ans++;
            }
            t++;
        }
    }
    cout << ans << endl;
    return 0;
}