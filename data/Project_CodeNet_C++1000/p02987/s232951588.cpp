#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if(s.at(0) == s.at(1) && s.at(1) != s.at(2) && s.at(2) == s.at(3)) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
