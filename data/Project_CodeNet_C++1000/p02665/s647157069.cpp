#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> as(n+1);
    for(int i=0; i<=n; i++)
    {
        cin >> as.at(i);
    }

    vector<ll> chotenmax(n+1); // chotenmax[i] 深さiの時に考えられる頂点の最大数
    chotenmax.at(0) = 1;
    for(int i=0; i<n; i++)
    {
        if(chotenmax.at(i) < as.at(i))
        {
            cout << "-1\n";
            return 0;
        }
        chotenmax.at(i+1) = (chotenmax.at(i) - as.at(i)) * 2;
        if(chotenmax.at(i+1) >= 1LL << 60) chotenmax.at(i+1) = 1LL << 60;
    }
    if(chotenmax.at(n) < as.back())
    {
        cout << "-1\n";
        return 0;
    }
    // for(auto ne : chotenmax) cout << ne << '\n';

    ll num = 0;
    ll ans = 0;
    for(int i=n; i>=0; i--)
    {
        num += as.at(i);
        if(chotenmax.at(i) < num) num = chotenmax.at(i);
        ans += num;
    }
    cout << ans << '\n';

    return 0;
}
