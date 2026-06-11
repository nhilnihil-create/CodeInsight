#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    int total = 0;
    int res = 0;
    string ans = "No";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        total += A[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (A[i] * 4 * m >= total)
        {
            res++;
        }
    }
    if (res >= m)
        ans = "Yes";

    cout << ans << endl;
}
