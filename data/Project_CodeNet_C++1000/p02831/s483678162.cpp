#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main()
{
    int a, b;
    cin >> a >> b;
    ll gcd = __gcd(a, b);
    ll lcm;
    lcm = a  / gcd * b;
    cout << lcm << endl;
    return 0;
}
