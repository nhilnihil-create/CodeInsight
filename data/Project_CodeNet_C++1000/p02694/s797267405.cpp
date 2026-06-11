#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
    ll c = 0;
    ll x,m=100;
    cin >> x;
    while(x > m)
    {
        m += m/100;
        c++;
    }
    cout << c << endl;
}
