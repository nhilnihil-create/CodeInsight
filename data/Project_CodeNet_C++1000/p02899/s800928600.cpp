#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
////////////////////////////////////////////////
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    rep(i, n)
    {
        int ai;
        cin >> ai;
        a[i] = make_pair(ai, i);
    }
    sort(a.begin(), a.end());
    for (auto i : a)
    {
        cout << i.second + 1;
        if (i.first != n)
            cout << " ";
    }
    cout << endl;
}