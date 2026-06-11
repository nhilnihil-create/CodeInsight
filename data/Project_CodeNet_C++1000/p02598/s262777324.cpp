#include <iostream>

using namespace std;

long long int n,k;
long long int a[200005];
bool check(long long int m)
{
    int sl = 0;
    for (long long int i = 1; i<= n ; i++ )
    {
        sl += (a[i]/m);
        if(a[i]%m == 0)
            sl --;
    }
    if (sl<=k) return true;
    return false;
}
int main()
{
    cin >> n >> k;
   long long int d = 1, c = -1, g, m = -1;
    for (long long int i = 1; i <= n ; i ++ )
    {
        cin >> a[i];
        if (c<a[i]) c=a[i];
    }

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

