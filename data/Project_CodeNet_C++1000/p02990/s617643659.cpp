#include <iostream>
using namespace std;
int a[2001][2001] = {0};
int main()
{
    int n, k;
    const int x = 1000000007;
    for(int i = 0; i <= 2000; i++)
    {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    for(int i = 2; i <= 2000; i++)
    {
        for(int j = 1; j < i; j++)
        {
            a[i][j] = (a[i - 1][j - 1] % x + a[i - 1][j] % x) % x;
        }
    }
    cin >> n >> k;
    for(int i = 1; i <= k; i++)
    {
        long long ans = 1;
        cout << (ans * a[k - 1][i - 1] * a[n - k + 1][i]) % x << endl;
    }
    return 0;
}
