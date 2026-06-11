#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int    n;
    double p1 = 0, p2 = 0, p3 = 0, p_inf = 0;
 
    do {
        cin >> n; 
    } while (n < 0 || n > 100);
       
    int* x = new int[n];
    int* y = new int[n]; 
    
    for (int i = 0; i < n; i++) {
         do {
             cin >> x[i];	    
         } while (x[i] < 0 || x[i] > 1000);
    }

    for (int i = 0; i < n; i++) {
         do {
             cin >> y[i];
         } while (y[i] < 0 || y[i] > 1000);
    }

    for (int i = 0; i < n; i++) {
         p1 += abs(x[i] - y[i]);
         p2 += pow(abs(x[i] - y[i]), 2);
         p3 += pow(abs(x[i] - y[i]), 3);

         if (abs(x[i] - y[i]) > p_inf) {
             p_inf = abs(x[i] - y[i]);
         }

         if (i == n - 1) {
	     p2 = sqrt(p2);
             p3 = pow(p3, 1.0 / 3.0);
         }
    }
   
    cout << fixed << setprecision(8) << p1 << endl;
    cout << fixed << setprecision(8) << p2 << endl;
    cout << fixed << setprecision(8) << p3 << endl;
    cout << fixed << setprecision(8) << p_inf << endl;
   
    delete[] x;
    delete[] y;

    return (0);
}
      