#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;
int A[200005];
int a[200005];

int main()
{
    int N, i, j, m;
    cin >> N;
    rep0(i, N) cin >> A[i];

    sort(A, A + N, greater<int>());

    long long ans = A[0];
    int t;

    rep(1, i, N)
    {
        if (2 * i + 1 <= N-1)
            ans += A[i] * 2;
        else if (2 * i + 1 == N)
            ans += A[i];
        else
            break;
    }
    cout << ans << endl;
    return 0;
}