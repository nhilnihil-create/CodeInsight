#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int Factorial(int k) {
    int sum = 1;
    for(int i = 1; i <= k; ++i) {
        sum *= i;
    }
    return sum;
}

int main() {
    int n;
    int x[10], y[10];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<int>v(n);
    for(int i = 0; i < n; i++) {
        v[i]=i;
    }

    int fac = Factorial(n);
    double ave = 0.0;
    for(int i = 0; i < fac; i++) {
        for(int j = 0; j < n - 1; j++) {
            ave += sqrt(pow(x[v[j]] - x[v[j + 1]], 2) + pow(y[v[j]] - y[v[j + 1]], 2));
        }
        next_permutation(v.begin(), v.end());
    }
    printf("%.10f\n", (double)ave / fac);
    return 0;
}
