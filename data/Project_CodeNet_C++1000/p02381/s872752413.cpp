#include <iostream>
#include <cmath>

int main()
{
    while(1) {
        int n = 0;
        std::cin >> n;

        if (n == 0) {
            break;
        }
        int a[1000];
        double r = 0;
        double s = 0;
        double sn = 0;
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        double sum = 0;
        double ave = 0;

        for (int i = 0; i < n; i++) {
            sum += a[i];
        }

        ave = sum / n;

        for (int i = 0; i < n; i++) {
            sn += (a[i] - ave) * (a[i] - ave);
        }

        s = sn / n;
        r = sqrt(s);


        std::printf("%lf\n", r);



    }


    return 0;

}