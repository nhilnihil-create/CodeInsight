#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long a;
    double b;

    cin >> a >> b;
    int bb = b * 100 + 0.5;

    cout << (unsigned long long)(a*bb)/100 << endl;

    return 0;
}