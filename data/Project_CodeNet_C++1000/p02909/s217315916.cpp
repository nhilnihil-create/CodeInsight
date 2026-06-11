#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

int main()
{
    Hello
    map<string, string> mp;
    mp["Sunny"] = "Cloudy";
    mp["Cloudy"] = "Rainy";
    mp["Rainy"] = "Sunny";
    string s;
    cin >> s;
    cout << mp[s];
    return 0;
}
