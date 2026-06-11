#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    vector<long long> a(k);
    a.at(0) = 7 % k;
    for (int i = 1; i < k; i++)
    {
        a.at(i) = (a.at(i - 1) * 10 + 7) % k;
    }

    int s = -1;
    for (int i = 0; i < k; i++)
    {
        if (a.at(i) == 0)
        {
            s = i + 1;
            break;
        }
    }

    cout << s << endl;
    return 0;
}
