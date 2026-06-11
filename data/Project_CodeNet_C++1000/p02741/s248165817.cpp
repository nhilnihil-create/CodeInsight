#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main()
{
    ll a[] = {  1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51 };
    ll n; cin >> n;
    for(ll i = 0 ; i < 32; i++)
    {
        if((i + 1) == n)
        {
            cout << a[i] << '\n';
            break;

        }
    }
}
