#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    int n; cin >> n;
    int A[n], B[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i] >> B[i];
    }
    sort(A, A+n); sort(B, B+n);
    if (n % 2 == 1)
    {
        cout << B[n/2] - A[n/2] + 1 << '\n';
    }
    else
    {
        cout << B[n/2] + B[n/2-1] - A[n/2] - A[n/2-1] + 1 << '\n';
    }
    return 0;
}