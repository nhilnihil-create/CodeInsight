#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define pi acos(-1.0)

int main()
{
    ll i, j, a, b, k, n, m, cnt = 0;
    string s;

    cin >> a >> b;

    ll lcm = (a * b) / __gcd(a, b);

    cout << lcm << endl;

    return 0;
}
