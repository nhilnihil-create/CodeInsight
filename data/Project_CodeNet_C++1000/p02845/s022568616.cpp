#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

int N;
int A[101010];
int num[101010][3];
ll ans = 1;

int main()
{
    cin >> N;
    rep(i, N)
    {
        cin >> A[i + 1];
        bool flag = true;
        int var = 0;
        for (int j = 0; j < 3; j++)
        {
            if (num[i][j] == A[i + 1])
            {
                var++;
            }
            if (flag && num[i][j] == A[i + 1])
            {
                num[i + 1][j] = num[i][j] + 1;
                flag = false;
            }
            else
            {
                num[i + 1][j] = num[i][j];
            }
        }
        ans = ans * var % MOD;
    }

    cout << ans << endl;
}
