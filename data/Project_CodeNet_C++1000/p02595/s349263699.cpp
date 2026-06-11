#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
 
using namespace std;
 
int main()
{
    int n;
    long long d;
    int count = 0;
    long long a, b;
 
    cin >> n >> d;
 
    d *= d;
 
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (a * a + b * b <= d)
        {
            count++;
        }
    }
    cout << count;
}