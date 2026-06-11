#include <bits/stdc++.h>

#define llint long long int

using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<int> A(N), B(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];

        B[i] = A[i];
    }
    sort(B.begin(), B.end(), greater<int>());

    for (int i = 0; i < N; i++)
    {
        if (A[i] == B[0])
        {
            cout << B[1] << endl;
        }
        else
        {
            cout << B[0] << endl;
        }
    }
}