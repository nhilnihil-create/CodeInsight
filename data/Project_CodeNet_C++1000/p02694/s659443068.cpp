#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using Graph = vector<vector<ll>>;

int main(void)
{
    ll x,money,count=0;
    cin >> x;
    money=100;
    while(money<x)
    {
        money+=money/100;
        count++;
    }
    cout << count << endl;
    return 0;
}
