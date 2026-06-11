#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll x, p=100;
    cin >> x;
    for(int i = 0; i < 4000; i++)
    {
        if(p>=x)
        {
            cout << i << endl;
            break;
        }
        p+=p/100;
    }
}
