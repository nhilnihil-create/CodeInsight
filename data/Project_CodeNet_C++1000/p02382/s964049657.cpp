#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double l1_distance = 0.0, l2_distance = 0.0, l_3_distance = 0.0, diff, l_infty = -99999;
    double x[100], y[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> y[i];
    }

    for (int i = 0; i < n; ++i)
    {
        diff = fabs(y[i] - x[i]);
        l1_distance += diff;
        l2_distance += diff * diff;
        l_3_distance += diff * diff * diff;
        l_infty = max(l_infty, diff);
    }
    l2_distance = sqrt(l2_distance);
    l_3_distance = pow(l_3_distance, 1.0 / 3.0);
    printf("%10.8f\n", l1_distance);
    printf("%10.8f\n", l2_distance);
    printf("%10.8f\n", l_3_distance);
    printf("%10.8f\n", l_infty);
}
