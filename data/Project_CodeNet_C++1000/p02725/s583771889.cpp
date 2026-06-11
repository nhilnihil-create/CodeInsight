#include<iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int gcd(int p, int q) {
    if (p % q == 0)return q;
    return gcd(q, p % q);
}

int main()
{
    int k,n;
    cin >> k>>n;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min,dif;
    min = a[n - 1] - a[0];

    for (int i = 0; i < n-1; i++) {
        dif = a[i] + k - a[i + 1];
        if (dif < min) min = dif;
    }

    cout << min;
    
    return 0;
}

