#include <iostream>
#include <cmath>

double abs(double a);


int main()
{
    int n;

    std::cin >> n;

    double x[n];
    double y[n];

    for (int i = 0;i < n; i++) {
        std::cin >> x[i];
    }

    for (int i = 0;i < n; i++) {
        std::cin >> y[i];
    }
    double p1 = 0,p2 = 0,p3 = 0,p8 = 0;

    //p=1
    for (int i = 0; i < n; i++) {
        p1 += abs(x[i] - y[i]);
    }

    //p=2
    for (int i = 0; i < n ; i++) {
        p2 += (x[i] - y[i]) * (x[i] - y[i]);
        if (i == n - 1) {
            p2 = sqrt(p2);
        }
    }

    //p=3
    for (int i = 0; i < n; i++) {
        p3 += abs((x[i] - y[i]) * (x[i] - y[i]) * (x[i] - y[i]));
        if (i == n - 1) {
            p3 = std::pow(p3, 1.0/3.0);
        }
    }

    //p=8
    for (int i = 0; i < n; i++) {
        if (p8 <= abs(x[i] -y[i])) {
            p8 = abs(x[i] - y[i]);
        }
    }

    std::printf("%lf\n%lf\n%lf\n%lf\n",p1,p2,p3,p8);

}

double abs(double a)
{
    if (a < 0) {
        return -a;
    } else {
        return a;
    }
}