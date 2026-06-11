#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <cmath>


using namespace std;
using ull = unsigned long long;

double Distance(const vector<int>& x, const vector<int>& y, int p)
{
    double d {};
    int n = x.size();
    if (p != numeric_limits<int>::max())
    {
        for (int i = 0; i < n; ++i)
            d += pow(abs(x[i] - y[i]), p);

        d = pow(d, 1 / static_cast<double>(p));
    }
    else
    {
        for (int i = 0; i < n; ++i)
            d = max(d, static_cast<double>(abs(x[i] - y[i])));
    }

    return d;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n && cin >> x[i]; ++i);
    for (int i = 0; i < n && cin >> y[i]; ++i);

    cout << fixed << setprecision(8);

    for (auto i : {1, 2, 3, numeric_limits<int>::max()})
    {
        cout << Distance(x, y, i) << endl;
    }


    return 0;
}