#include <iostream>
#include <cmath>
using namespace std;
typedef long long  ll;
int main ()
{
    ll t1, t2;
    ll a1, a2, b1, b2;
    cin >> t1 >> t2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    ll sa1 = a1 * t1, sa2 = a2 * t2;
    ll sb1 = b1 * t1, sb2 = b2 * t2;
    ll suma =sa1 + sa2 , sumb = sb1 + sb2;
    if(suma == sumb)
        cout << "infinity" << endl;
    else
    {
        if(sa1 < sb1 && suma < sumb || sa1 > sb1 && suma > sumb)
            cout << 0 <<endl;
        else if(sa1 < sb1 && suma > sumb || sa1 > sb1 && suma < sumb)
        {
            ll k1 = abs(suma - sumb);
            ll k2 = abs(sa1 - sb1);
            ll k3 = k2 / k1;
            if(k3 * k1 == k2)
                cout << 2 * k3 << endl;
            else
                cout << 2 * k3 + 1 << endl;
        }

    }
    return 0;
}