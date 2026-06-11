#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;
    int t = x;
    int k = 1;
    while( t % 360 != 0 )
    {
        k++;
        t += x;
    }

    cout << k;
}