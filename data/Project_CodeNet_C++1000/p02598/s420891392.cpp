#include <iostream>

using namespace std;

long long int n,k;
long long int a[100000009];
bool check(int m)
{
    long long int sl = 0;
    for (long long int i = 1; i<= n ; i++ )
    {
        sl += (a[i]/m);
        if(a[i]%m == 0) sl --;
    }
    return (sl <= k);
}
int main()
{
    cin >> n >> k;
    long long int d = 1, c = -1 , g, m = -1;
    for (long long int i = 1; i <= n ; i ++ )
        {
            cin >> a[i];
            c = max(c,a[i]);}

    while ( d <= c )
    {
        g = (d+c)/2;
        if (check(g))
        {
            m = g;
            c = g - 1;
        }
        else
            d = g + 1;
    }
    cout << m;
    return 0;
}
