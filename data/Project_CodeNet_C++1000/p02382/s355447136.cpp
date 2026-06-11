#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

void print_minkowski_distance(int n, int x[], int y[], double p)
{
    double d = 0.0;
    for(int i=0;i<n;i++)
    {
        d += pow(abs(x[i]-y[i]), p);
    }
    d = pow(d, 1.0/p);
    cout << fixed << d << endl;    
}

int main()
{
    int n;
    cin >> n;
    int x[n], y[n];
    for(int i=0;i<n;i++)
    {
        cin >> x[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> y[i];
    }

    print_minkowski_distance(n, x, y, 1);
    print_minkowski_distance(n, x, y, 2);
    print_minkowski_distance(n, x, y, 3);
    
    int d=abs(x[0]-y[0]);
    for(int i=1;i<n;i++)
    {
        d = max(d, abs(x[i]-y[i]));
    }
    cout << fixed << (double)d << endl;
    
    return 0;
}

