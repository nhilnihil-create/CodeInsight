#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll f(ll n)
{
    return n * (n-1) / 2;
}

int main(){
    ll n;
    cin >> n;

    vector<ll> as(n);
    vector<ll> cnt(n+1, 0);
    for(size_t i = 0; i < n; ++i)
    {
        cin >> as.at(i);
        cnt.at(as.at(i))++;
    }

    ll total = 0;
    for(size_t i = 0; i <= n; ++i)
        total += f(cnt.at(i));

    for(size_t i = 0; i < n; ++i)
    {
        cout << total - cnt.at(as.at(i)) + 1 << endl;
    }

    return 0;
}
