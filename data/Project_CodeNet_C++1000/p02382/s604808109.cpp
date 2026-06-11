#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    u_int n;
    cin >> n;
    
    int x[n], y[n];
    for (u_int i = 0; i < n; i++)
        cin >> x[i];
    for (u_int i = 0; i < n; i++)
        cin >> y[i];

    double manh[4] = {0, 0, 0, 0};

    for (u_int i = 0; i < n; i++) {
        double d = abs(x[i] - y[i]);
        manh[0] += d;
        manh[1] += d * d;
        manh[2] += d * d * d;
        if (d > manh[3])
            manh[3] = d;
    }

    manh[1] = sqrt(manh[1]);
    manh[2] = pow(manh[2], 0.333333333333);

    printf("%f\n%f\n%f\n%f\n", manh[0], manh[1], manh[2], manh[3]);

    return 0;
}