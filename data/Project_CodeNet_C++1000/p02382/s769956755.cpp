#include<bits/stdc++.h>
using std::cout;
using std::cin;
using std::endl;

void distance(const int *x, int n, double p)
{
    double sum=0;
    int dec[n];
    for (int i = 0; i < n; i++)
    {
        dec[i] = pow(*x++, p);
        sum += (double)dec[i];
    }
    sum = pow(sum, 1/p);

    cout << sum << endl;
}

int main()
{
    cout<< std::fixed << std::setprecision(6);
    int n;
    cin >> n;
    int x[n], y[n], dec[n];

    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> y[i];    

    for (int i = 0; i < n; i++)
        dec[i] = abs(x[i] - y[i]);
    
    distance(dec, n, 1);
    distance(dec, n, 2);
    distance(dec, n, 3);

    double mx=0;
    for (int i = 0; i < n; i++)
        mx = fmax(mx, abs(x[i]-y[i]));

    cout << mx << endl;
    

    return 0;
}
