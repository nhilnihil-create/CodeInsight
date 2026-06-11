#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    unsigned long long int a, b, n;
    cin >> a >> b >> n;
    unsigned long long int x = b - 1 < n ? b - 1: n;
    cout << (a * x) / b - a * (x / b) << endl;
    return 0;
} 