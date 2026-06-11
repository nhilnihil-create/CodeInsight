#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b, k;
    cin >> a >> b >> k;
    long long z = a;
    a -= min(a, k);
    k -= min(z, k);
    b -= min(k, b);
    cout << a << " " << b << endl;
}
