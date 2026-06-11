#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void)
{
    ll a, b, c, d;
    ll x[4];    

    cin >> a >> b >> c >> d;
    x[0] = a * c;
    x[1] = a * d;
    x[2] = b * c;
    x[3] = b * d;
    sort(x, x + 4);
    cout << x[3] << endl;
    return 0;
}