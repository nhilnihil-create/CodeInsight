#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    long long n, sum, a, i, b;
    cin >> n;
    sum = 1;
    b = 1;
    a = 1;
 
    for (i = 0; i < n; i++)
    {
        sum = (10 * sum) % 1000000007;
        b = (9 * b) % 1000000007;
        a = (8 * a) % 1000000007;
    }
    while (sum - 2 * b + a < 0)
    {
        sum += 1000000007;
    }
    if (n == 1)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << sum - 2 * b + a << endl;
    }
    return 0;
}