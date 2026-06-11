#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll x;
    cin >> x;
    ll b = (x/500)*1000;
    if(x%500) b+=(x-(b/2))/5*5;
    cout << b;
}

