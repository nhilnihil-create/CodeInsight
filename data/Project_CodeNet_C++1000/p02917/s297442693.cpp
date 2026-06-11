#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N;
    cin >> N;
    vector<int> B(N - 1), A(N);

    for (int i = 0; i < N - 1; i++)
        cin >> B[i];

    for (int i = 1; i < N - 1; i++)
        A[i] = min(B[i - 1], B[i]);

    A[0] = B[0], A[N - 1] = B[N - 2];
    int ans = 0;
    for (auto x : A)
        ans += x;
    cout << ans;
}