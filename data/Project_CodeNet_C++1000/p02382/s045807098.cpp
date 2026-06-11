#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <cmath>

#define REP(i, n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define square(x) (x) * (x)
#define cube(x) (x) * (x) * (x)

const int INF = 1e9;

using namespace std;

int main() {
    int n;
    cin >> n;
    int x[n];
    int y[n];
    long double manhattan = 0;
    long double euclid = 0;
    long double cdist = 0;
    int chebyshev = 0;
    REP(i, n)
        cin >> x[i];
    REP(i, n){
        cin >> y[i];
        manhattan += abs(x[i] - y[i]);
        euclid += square(x[i] - y[i]);
        cdist += cube(abs(x[i] - y[i]));
        chebyshev = max(chebyshev, abs(x[i] - y[i]));
    }
    cout << setprecision(10);
    cout << manhattan << endl << sqrt(euclid) << endl << cbrt(cdist) << endl << chebyshev << endl;

    return 0;
}