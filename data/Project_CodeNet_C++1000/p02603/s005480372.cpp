#include<iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;


int main()
{
    int n;
    cin >>n;
    vector<long long> a(n, 0);
    long long m = 1000;
    long long kabu;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (long long i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) {
            kabu = m / a[i];
            m = m % a[i];
            m = m + kabu * a[i + 1];
        }
    }

    cout << m;

    return 0;
}

