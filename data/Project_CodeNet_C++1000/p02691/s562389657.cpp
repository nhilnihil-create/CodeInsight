#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> as(n);
    for(int i=0; i<n; i++) cin >> as.at(i);

    map<int, ll> imp, jmp;
    for(int i=0; i<n; i++)
    {
        imp[as.at(i)+i+1]++;
        jmp[-as.at(i)+i+1]++;
    }
    ll ans = 0;
    for(auto itr = imp.begin(); itr != imp.end(); itr++)
    {
        ans += jmp[itr->first] * itr->second;
    }
    cout << ans << endl;

    return 0;
}