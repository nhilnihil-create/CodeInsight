#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int N;
    cin >> N;

    vector<int> A(N + 1);
    for (int i = 0; i < N + 1; i++)
    {
        cin >> A[i];
    }
    vector<int> B(N);
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += min(A[i], B[i]);
        B[i] -= min(A[i], B[i]);
        A[i] -= min(A[i], B[i]);
        sum += min(A[i + 1], B[i]);
        A[i + 1] -= min(A[i + 1], B[i]);
        // if (A[i] <= B[i])
        // {
        //     sum += A[i];
        //     B[i] -= A[i];

        //     if (A[i + 1] <= B[i] && B[i] > 0)
        //     {
        //         sum += A[i + 1];
        //         B[i] -= A[i + 1];
        //     }
        //     else if (A[i + 1] >= B[i] && B[i] > 0)
        //     {
        //         sum += B[i];
        //         A[i + 1] -= B[i];
        //     }
        // }
        // else
        // {
        //     sum += B[i];
        //     A[i] -= B[i];
        // }
    }
    cout << sum << endl;
    return (0);
}