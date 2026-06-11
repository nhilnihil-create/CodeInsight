#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
    int n, i, count;
    double d, r;
    double x[200000];
    double y[200000];
    count = 0;
    cin >> n;
    cin >> d;
    for (i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        r = sqrt(x[i] * x[i] + y[i] * y[i]);
        if (r <= d)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}