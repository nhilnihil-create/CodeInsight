/*
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_10_D
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

double
cubic(const double a)
{
    return a * a * a;
}

double
square(const double a)
{
    return a * a;
}

int
main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n; cin.ignore();

    vector<double> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i]; cin.ignore();
    }
    vector<double> y(n);
    for (int i = 0; i < n; i++) {
        cin >> y[i]; cin.ignore();
    }

    vector<double> d;
    for (int i = 0; i < n; i++) {
        d.push_back( abs( x[i] - y[i] ) );
    }
    x.clear();
    y.clear();

    cout << setprecision(6) << fixed;

    cout << accumulate(d.cbegin(), d.cend(), 0.0) << endl;

    vector<double> d2;
    transform(d.begin(), d.end(), back_inserter(d2), square);
    cout << sqrt( accumulate(d2.cbegin(), d2.cend(), 0.0) ) << endl;
    d2.clear();

    transform(d.cbegin(), d.cend(), back_inserter(d2), cubic);
    cout << cbrt( accumulate(d2.cbegin(), d2.cend(), 0.0) ) << endl;
    d2.clear();

    sort(d.begin(), d.end(), greater<double>());
    auto it = d.cbegin(); 
    cout << *it << endl;
    d.clear();

    return 0;
}