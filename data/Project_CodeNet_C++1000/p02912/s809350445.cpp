#include <bits/stdc++.h>
#define int long long
using pii=std::pair<int,int>;
using namespace std;

int n, m, a;
multiset<int, greater<int>> prices;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        prices.insert(a);
    }
    for(int i = 0; i < m; i++)
    {
        int largest = *prices.begin();
        prices.erase(prices.begin());
        prices.insert(largest / 2);
    }
    int ans = 0;
    for(auto x : prices)
        ans += x;
    cout << ans << "\n";
    return 0;
}