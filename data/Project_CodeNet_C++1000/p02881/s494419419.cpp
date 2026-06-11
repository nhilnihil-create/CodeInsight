#include<iostream>
#include<cstdlib>
using namespace std;
#define ll long long 
int main()
{
    ll int x, y, n, i, ans, d;
    cin >> n;
    ans = n;
    for(i = 1; i * i <= n; i++)
    {
        if(n%i == 0)
        {
            x = i;
            y = n/i;
            d = x + y - 2;
            if(d < ans)
            ans = d;
        }
    }
    cout << ans;
    return 0;
}