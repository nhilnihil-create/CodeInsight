#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> as(n);
    for(int i=0; i<n; i++) cin >> as.at(i);

    ll sun = 0;
    for(auto a : as) sun += a;

    ll prea = 0;
    for(auto &a : as)
    {
        a += prea;
        prea = a;
    }

    ll nea = 0;
    for(auto a : as)
    {
        if(abs(2*a - sun) < abs(sun - nea)) nea = 2*a;
    }
    cout << abs(sun - nea) << endl;

    return 0;
}
