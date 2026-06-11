#include<bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;

using ll = long long;
const int N = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(0);

    int n,mx = 0;
    cin >> n;
    map<string,int> mp;
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        mp[s]++;
        mx = max(mx, mp[s]);
    }
    vector<pair<int,string>> a;
    for(auto itr : mp) {
        a.push_back({itr.second, itr.first});
    }
    sort(a.rbegin(), a.rend());

    vector<string> ans;
    for(auto itr : a) {
        if(itr.first == mx) ans.push_back(itr.second);
        else break;
    }
    sort(ans.begin(), ans.end());
    for(auto itr : ans)
        cout << itr << "\n";
    return 0;
}
