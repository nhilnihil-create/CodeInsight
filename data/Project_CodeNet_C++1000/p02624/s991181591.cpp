#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    long long n, s, mid;
    cin >> n;
    mid = n / 2;
    for (long long i = 1; i <= mid; i++) {
        long long k = n / i;
        s += k * (k + 1) / 2 * i;
    }
    s += (mid + 1 + n) * (n - mid) / 2;
    cout << s << endl;
    return 0;
}