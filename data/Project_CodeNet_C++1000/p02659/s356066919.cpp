#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a;
    long double b;
    cin >> a >> b;
    b *= 100;
    long long c = (long long)(b + 0.5);
    cout << a * c / 100 << endl;
}

