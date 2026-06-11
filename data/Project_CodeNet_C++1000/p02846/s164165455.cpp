#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long T[2], A[2], B[2];

    cin >> T[1] >> T[2] >> A[1] >> A[2] >> B[1] >> B[2];

    if (A[1] < B[1])
    {
        swap(A[1], B[1]);
        swap(A[2], B[2]);
    }

    long long C[2], D[2];

    C[1] = A[1] - B[1];
    C[2] = A[2] - B[2];

    D[1] = T[1] * C[1];
    D[2] = T[2] * C[2];

    if (D[1] + D[2] > 0)
    {
        cout << 0 << endl;
        exit(0);
    }

    else if (D[1] + D[2] == 0)
    {
        cout << "infinity" << endl;
        exit(0);
    }

    if (D[1] % (abs(D[2]) - D[1]) != 0)
    {
        cout << (D[1] / (abs(D[2]) - D[1])) * 2 + 1 << endl;
    }

    else
    {
        cout << (D[1] / (abs(D[2]) - D[1])) * 2 << endl;
    }
}
