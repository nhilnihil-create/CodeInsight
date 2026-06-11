#include <bits/stdc++.h>
using namespace std;

int main()
{
    size_t N;
    cin >> N;

    vector<long long> A(N);
    vector<long long> B(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if (N % 2 == 0)
    {
        long long l2 = A[N / 2] + A[N / 2 - 1];
        long long r2 = B[N / 2] + B[N / 2 - 1];
        cout << r2 - l2 + 1 << endl;
    }
    else
    {
        long long l = A[N / 2];
        long long r = B[N / 2];
        cout << r - l + 1 << endl;
    }
}
