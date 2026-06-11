#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    vector<int> a(3);
    rep (i, 3)
        cin >> a[i];

    if (accumulate(a.begin(), a.end(), 0) > 21)
        cout << "bust" << endl;
    else
        cout << "win" << endl;
    return 0;
}