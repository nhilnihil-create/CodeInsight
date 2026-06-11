#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    while (true) {
        u_int n;
        cin >> n;
        if (!n)
            break;

        u_int data[n];
        double ave = 0;
        for (u_int i = 0; i < n; i++) {
            cin >> data[i];
            ave += data[i];
        }
        ave /= n;

        double dev = 0;
        for (u_int i = 0; i < n; i++)
            dev += (data[i] - ave) * (data[i] - ave);
        dev = sqrt(dev / n);
        
        printf("%f\n", dev);
    }
    
    return 0;
}