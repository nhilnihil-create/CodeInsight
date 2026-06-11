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
    for(int i=0; i<n+1; i++) cin >> as.at(i);
    vector<int> bs(n);
    for(int i=0; i<n; i++) cin >> bs.at(i);

    ll ans = 0;
    for(int i=n-1; i>=0; i--)
    {
        int ti1 = (as.at(i+1) <= bs.at(i)) ? as.at(i+1) : bs.at(i);
        ans += ti1;
        bs.at(i) -= ti1;
        int ti0 = (as.at(i) <= bs.at(i)) ? as.at(i) : bs.at(i);
        ans += ti0;
        as.at(i) -= ti0;
    }
    cout << ans << endl;

    return 0;
}
