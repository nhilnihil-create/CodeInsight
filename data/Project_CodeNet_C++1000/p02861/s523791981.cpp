#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for(int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    vector<int> p(n);
    for(int i = 0; i < n; ++i)
        p[i] = i;

    double len = 0;
    int cnt = 0;
    do {
        for(int i = 0; i < n - 1; ++i)
        {
            double dx = x[p[i]] - x[p[i + 1]];
            double dy = y[p[i]] - y[p[i + 1]];
            len += sqrt(dx * dx + dy * dy);;
        }
        cnt++;
    } while(next_permutation(p.begin(), p.end()));

    double res = len / cnt;
    cout << setprecision(10) << fixed << res << "\n"; 
    return 0;
}