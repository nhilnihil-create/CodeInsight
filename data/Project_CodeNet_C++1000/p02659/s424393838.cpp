#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
int main()
{
    ll a;
    double b;
    cin >> a >> b;
    ll c = round(b * ll(100));
    cout << (a*c)/ll(100) << endl;
    return 0;
}