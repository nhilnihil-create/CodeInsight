#include<bits/stdc++.h>
using namespace std;
using ll =  long long;
int main()
{
    ll a , b;
    cin >> a >> b;
    cout << (ll)(a * b)/__gcd(a, b) << endl;
}
