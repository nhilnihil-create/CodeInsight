#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
    int n, x[1001], y[1001];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
    }

    double p1, p2, p3, p_inf = 0.0;
    for (int i = 0; i < n; i++)
    {
        p1 += abs(x[i] - y[i]);
        p2 += pow(abs(x[i] - y[i]), 2);
        p3 += pow(abs(x[i] - y[i]), 3);
        if (p_inf < abs(x[i] - y[i]))
        {
            p_inf = abs(x[i] - y[i]);
        }
    }
    p2 = sqrt(p2);
    p3 = pow(p3, 1.0 / 3.0);
    
    cout << fixed << setprecision(6) << p1 << endl << p2 << endl << p3 << endl << p_inf << endl;

    return 0;
}
