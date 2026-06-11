#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll k, q;
    cin >> k >> q;
    ll d[5003];
    for(int i = 0; i < k; i++) cin >> d[i];
    for(int c = 0; c < q; c++){
        ll n, x, m;
        cin >> n >> x >> m;
        x %= m;
        ll f[5003];
        f[0] = 0;
        ll eq = 0;
        for(int i = 1; i <= k; i++){
            f[i] = f[i - 1] + d[i - 1] % m;
            if(d[i - 1] % m == 0){
                eq += (n - 1) / k;
                if(i <= (n - 1) % k) eq++;
            }
        }
        ll r = x + f[k] * ((n - 1) / k) + f[(n - 1) % k];
        cout << n - 1 - eq - r / m << endl;
    }
}
