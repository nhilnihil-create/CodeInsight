#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> kosu(n);
    rep(i, n)
    {
        cin >> a.at(i);
        kosu.at(a.at(i) - 1)++;
    }

    ll sum = 0;
    rep(i, n)
    {
        sum += kosu.at(i) * (kosu.at(i) - 1) / 2;
    }

    for (int k = 0; k < n; k++)
    {
        ll b ;
        b = sum + (kosu.at(a.at(k)-1)-1)*(kosu.at(a.at(k)-1)-2)/2 -(kosu.at(a.at(k)-1))*(kosu.at(a.at(k)-1)-1)/2 ;
        cout << b << endl ;
    }
}