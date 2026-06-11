#include <bits/stdc++.h>
#define pii pair<int,int>
#define eb emplace_back
#define MOD 1000000007
#define int long long
using namespace std;
#define s second
#define f first

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    cin>>T;
    map<string,int> mp;
    while(T --> 0)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    cout << "AC x " << mp["AC"]<<'\n';
    cout << "WA x " << mp["WA"]<<'\n';
    cout << "TLE x " << mp["TLE"]<<'\n';
    cout << "RE x " << mp["RE"];
}