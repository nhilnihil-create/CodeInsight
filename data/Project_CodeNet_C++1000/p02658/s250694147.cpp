//time:
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long ans = 1;
    long long p = 1000000000000000000;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i);
        if (a.at(i) == 0)
        {
            ans = 0;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (ans == 0)
        {
            break;
        }
        else if (ans <= p / a.at(i))
        {
            ans *= a.at(i);
        }
        else
        {
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}