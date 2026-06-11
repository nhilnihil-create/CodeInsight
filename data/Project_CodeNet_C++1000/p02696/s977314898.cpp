#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int64_t A, B, N;
    cin >> A >> B >> N;
    int64_t x = min(B - 1, N);
    int64_t ans = floor(A * x / B);
    cout << ans << endl;
}