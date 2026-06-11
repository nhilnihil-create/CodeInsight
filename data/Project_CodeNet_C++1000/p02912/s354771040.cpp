#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

#define ll long long

int main()
{
    multiset<ll> st;
    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        st.insert(a);
    }

    for (ll i = 0; i < m; i++)
    {
        auto it = --st.end();
        st.erase(it);
        st.insert(*it / 2);
    }

    ll ans = 0;
    for (auto it = st.begin(); it != st.end(); it++) ans += *it;
    
    cout << ans << "\n";
}