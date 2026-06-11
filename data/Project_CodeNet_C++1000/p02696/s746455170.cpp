#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define _LL long long

int main()
{
    _LL a, b, n;
    cin >> a >> b >> n;
    cout << a * min(n, b - 1) / b;
}