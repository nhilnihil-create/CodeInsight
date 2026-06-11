#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;

    vector<int> x(n);
    rep(i, n)
        cin >> x.at(i);

    int s = 0;
    rep(i, n)
        s += x.at(i);

    int a = round((((double) s) / n));

    int d = 0;
    rep(i, n)
        d += (x.at(i) - a) * (x.at(i) - a);

    cout << d << endl;
}