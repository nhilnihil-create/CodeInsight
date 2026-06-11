#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
int main()
{
    ll d,t,s;
    cin >> d >> t >> s;
    if(t * s >= d)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    
    return 0;
}