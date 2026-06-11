#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main()
{
    ll a, b, c , d;
    cin >> a >> b >> c >> d;
    
    ll t1 = a*c;
    ll t2 = a*d;
    ll t3 = b*c;
    ll t4 = b*d;
    
    cout << max(max(t1, t2), max(t3, t4));
}