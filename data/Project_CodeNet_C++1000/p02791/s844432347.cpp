#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, res = 0;
    cin >> n;

    vector<int> p(n);
    for(int i = 0; i < n; ++i)
        cin >> p[i];

    int mn = p[0];
    for(int i = 0; i < n; ++i)
    {
        if(p[i] <= mn) res++;
        mn = min(mn, p[i]);
    }
    cout << res << "\n";
    return 0;
}