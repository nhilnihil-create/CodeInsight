#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define pi acos(-1.0)

int main()
{
    ll i, j, n, m;

    map < string, int > mp;

    mp["SUN"] = 7;
    mp["MON"] = 6;
    mp["TUE"] = 5;
    mp["WED"] = 4;
    mp["THU"] = 3;
    mp["FRI"] = 2;
    mp["SAT"] = 1;

    string s;

    cin >> s;

    cout << mp[s] << endl;

    return 0;
}
