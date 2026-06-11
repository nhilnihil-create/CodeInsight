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

    vector<long long> a(n,0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    long long sum = 0;
    sum = a[n - 1];
    int x = n - 2;

    for (int i = 0; i <n-2; i++) {
        sum += a[x];
        if (i <n-3 ) {
            sum += a[x];
            x--;
            i++;
        }
    }

    cout << sum;
   

    return 0;
}

