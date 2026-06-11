#include<iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;
#define INT_MAX       2147483647    // maximum (signed) int value

int gcd(int p, int q) {
    if (p % q == 0)return q;
    return gcd(q, p % q);
}

int main()
{
    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x.begin(), x.end());
    long long sum, min = INT_MAX;

    for (int i = x[0]; i <= x[n - 1]; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            sum += (x[j] - i)*(x[j] - i);
        }
        if (sum < min) min = sum;
    }

    cout << min;

    return 0;
}

