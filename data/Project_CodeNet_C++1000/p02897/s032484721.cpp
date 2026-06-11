#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    cin >> n;
    a=n;
    if(n%2)n/=2, n++;
    else n/=2;
    cout << fixed << setprecision(10) << (double)n/a;
}
