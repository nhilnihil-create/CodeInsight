#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n, 0);
    vector<ll> cnt(n+10, 0);
    for (int i = 0; i < n; i++){
        cin >> a.at(i);
        cnt.at(a.at(i))++;
    }
    
    ll sum = 0;
    for (ll c : cnt)
    {
        sum += (c-1)*c/2;
    }


    for (int i = 0; i < n; i++)
    {
        cout << sum - (ll)(cnt.at(a.at(i)) - 1) << endl;
    }

    return 0;
}