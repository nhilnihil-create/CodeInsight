#include <bits/stdc++.h>

using namespace std;

int main()
{
 
    long long int n,d,x,y,dem = 0,m;
    cin >> n >> d;
    while (n--)
    {
        cin >> x>>y;
        if ( sqrt(x*x+y*y) <= d)
            dem++;
    }
    cout << dem;
    return 0;
}
