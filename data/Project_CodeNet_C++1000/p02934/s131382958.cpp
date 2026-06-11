#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    double A[N];
    double inv_sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        inv_sum += 1 / A[i];
    }
    cout << setprecision(10) << fixed << 1 / inv_sum << endl;
}