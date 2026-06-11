#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> x,y;
    for(int i = 0;i < n;i++)
    {
        int t;
        cin >> t;
        x.push_back(t);
    }
    for(int i = 0;i < n;i++)
    {
        int t;
        cin >> t;
        y.push_back(t);
    }
    double d1 = 0;
    double d2 = 0;
    double d3 = 0;
    int d4 = 0;
    for(int i = 0;i < n;i++)
    {
        d1 += abs(x[i] - y[i]);
        d2 += abs(x[i] - y[i]) * abs(x[i] - y[i]);
        d3 += abs(x[i] - y[i]) * abs(x[i] - y[i]) * abs(x[i] - y[i]);
        if(abs(x[i] - y[i]) > d4)
        {
            d4 = abs(x[i] - y[i]);
        }
    }
    cout << fixed << setprecision(8) << d1 << endl << sqrt(d2) << endl << cbrt(d3) << endl << (double)d4 << endl;
}