#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int x[102] = {};
    int y[102] = {};
    long int sum;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> y[i];
    }

    //p=1
    sum = 0;
    for(int i = 0; i < n; i++) {
        sum += abs(x[i] - y[i]);        
    }
    printf("%.10lf\n", (double)sum);

    //p=2
    sum = 0;
    for(int i = 0; i < n; i++) {
        sum += (x[i] - y[i])*(x[i] - y[i]);        
    }
    printf("%.10lf\n", sqrt(sum));

    //p=3
    sum = 0;
    for(int i = 0; i < n; i++) {
        sum += abs(x[i] - y[i])*abs(x[i] - y[i])*abs(x[i] - y[i]);        
    }
    printf("%.10lf\n", pow(sum, 1.0/3.0));

    //p=inf
    sum = 0;
    int max = 0;
    for(int i = 0; i < n; i++) {
        if(max < abs(x[i]-y[i])) max = abs(x[i]-y[i]);
    }
    printf("%.10lf\n", (double)max);
    return 0;
}
