#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
long double distance(long double x1, long double y1, long double x2, long double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main() {
    int n;
    cin >> n;
    long double x[n], y[n];
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }
    long double avg = 0;
    for (int i=0; i<n; i++) {
        long double avg_i = 0;
        for (int j=0; j<n; j++) {
            avg_i += distance(x[i], y[i], x[j], y[j]);
        }
        avg += avg_i;
    }
    avg /= n;
    cout << fixed;
    cout << setprecision(6);
    cout << avg << endl;
}