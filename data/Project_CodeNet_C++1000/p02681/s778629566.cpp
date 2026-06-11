#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
string s, t;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> t;
    if(s.size() == t.size() - 1 && s == t.substr(0, s.size()))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
