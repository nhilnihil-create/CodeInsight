#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, n;
    cin >> h >> n;
    int64_t a;
    int64_t s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        s += a;
    }

    if (h > s)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}