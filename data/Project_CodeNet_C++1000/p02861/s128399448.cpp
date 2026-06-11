#include <iostream>
#include <cmath>

#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1  - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}

int main() {
    int n;
    cin >> n;
    int x[n];
    int y[n];
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        cin >> y[i];
        v.push_back(i);
    }
    double sum = 0;
    cout << setprecision(10);
    do {
        for (int i = 0; i < n - 1; ++i) {
            sum += distance(x[v[i]], y[v[i]], x[v[i+1]], y[v[i+1]]);
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << sum / factorial(n);
}
