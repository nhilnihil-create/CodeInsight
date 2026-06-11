#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll sum = 0;

    sum += (b / c - (a - 1) / c) + (b / d - (a - 1) / d) - (b / lcm(c,d) - (a - 1) / lcm(c,d));
    cout << (b-a+1)-sum << endl;

}