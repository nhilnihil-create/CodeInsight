#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(6) << fixed;
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for(int i = 0 ; i < n;i++)
        cin >> x[i];
    for(int i = 0 ; i < n;i++)
        cin >> y[i];

    double p1 = 0;
    double p2 = 0;
    double p3 = 0;
    double p4 = 0;
    for(int i = 0; i < n; i++){
        p1 += abs(x[i] - y[i]);
        p2 += pow(abs(x[i] - y[i]),2);
        p3 += pow(abs(x[i] - y[i]),3);
        p4 = max(p4,(double)abs(x[i] - y[i]));
    }
    cout << p1 << endl;
    cout << sqrt(p2) << endl;
    cout << pow(p3,(double)1/3) << endl;
    cout << p4 << endl;
    return 0;
}

