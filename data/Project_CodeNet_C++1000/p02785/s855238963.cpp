#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
    ll n, k;
    cin >> n >> k;
    vector<ll> h(n,0);
    for (int i = 0; i < n; ++i) scanf("%lld", &h[i]);

    sort(h.begin(), h.end(), std::greater<ll>());

    ll sum = 0;

    for (ll i = k; i < n; i++)
    {
        sum += h[i];
    }

    cout << sum << endl;
    

    return 0;
}
