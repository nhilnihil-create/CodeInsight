#include <bits/stdc++.h>

using namespace std;

int main()
{   long long n ;
    cin >> n;
    long long a[n];
    long long sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        if ((i % 3 == 0 || i % 5 == 0))
            a[i] = 0;
        else
            a[i] = i;
            sum = sum + a[i];
        }
        cout << sum;

}



