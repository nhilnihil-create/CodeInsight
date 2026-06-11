#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int k;
    cin >> k;
    int sig[1000001];
    sig[0] = 0, sig[1] = 7 % k;
    int ans = -1;
    for (int i = 2; i <= k; i++)
    {
        sig[i] = (sig[i - 1] * 10 + 7) % k;
    }
    for (int i = 1; i <= k; i++)
    {
        if (sig[i] == 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}