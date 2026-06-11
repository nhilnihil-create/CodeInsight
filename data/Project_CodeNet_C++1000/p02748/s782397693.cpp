#include <bits/stdc++.h>
using namespace std;

int main()
{
    int F, O, T, i, n, x, a, b, c, d;
    cin >> F >> O >> T;
    vector <int> f, o, t;
    for(i=0;i<F;i++)
    {
        cin >> n;
        f.push_back(n);
    }
    for(i=0;i<O;i++)
    {
        cin >> n;
        o.push_back(n);
    }
    for(i=0;i<T;i++)
    {
        cin >> a >> b >> c;
        d = (f[a-1] + o[b-1]) - c;
        t.push_back(d);
    }
    sort(o.begin(), o.end());
    sort(f.begin(), f.end());
    x = f[0] + o[0];
    sort(t.begin(), t.end());
    if(x<t[0])
    {
        cout << x << endl;
    }
    else
    {
        cout << t[0] << endl;
    }
    return 0;
}