#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    double sum;
    cin >> n;
    int x[n], y[n];
    for (int i=0; i<n; i++) cin >> x[i];
    for (int i=0; i<n; i++) cin >> y[i];
    // p = 1
    sum = 0;
    for (int i=0; i<n; i++) sum += abs(x[i]-y[i]);
    cout << fixed << setprecision(6) << sum << endl;
    // p = 2
    sum = 0;
    for (int i=0; i<n; i++) sum += pow(x[i]-y[i], 2);
    cout << fixed << setprecision(6) << sqrt(sum) << endl;
    // p = 3
    sum = 0;
    for (int i=0; i<n; i++) sum += pow(abs(x[i]-y[i]), 3);
    cout << fixed << setprecision(6) << pow(sum, 1.0/3.0) << endl;
    // p = inf
    m = abs(x[0]-y[0]);
    for (int i=1; i<n; i++) m = max(m, abs(x[i]-y[i]));
    cout << fixed << setprecision(6) << (double)m << endl;
    return 0;
}
