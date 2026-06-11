#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll arr[10004];

ll min(ll a, ll b) {
    return a < b ? a : b;
}

ll max(ll a, ll b) {
    return a > b ? a : b;
}

int main() {
    ll n,m;
    cin >> n >> m;
    ll res ;
    ll a = n%m;
    if (a < 0) a += m;
    cout << min(a, m-a) << "\n";
}
