#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int k, n;
    cin >> k >> n;

    vector<int> a(n);
    rep(i, n)
        cin >> a.at(i);

    int m = 0;
    rep(i, n) {
        if (i != n - 1)
            m = max(m, a.at(i + 1) - a.at(i));
        else
            m = max(m, (k - a.at(i)) + a.at(0));
    }

    cout << (k - m) << endl;
}
