#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

bool check(string s)
{
    string tmp;
    tmp = s;
    reverse(tmp.begin(), tmp.end());
    if (s.compare(tmp) != 0)
        return false;
    else
        return true;
}

int main()
{
    int n;
    string s, tmp1, tmp2;
    cin >> s;

    if (check(s) && check(s.substr(0, (s.length() - 1) / 2)) 
        && check(s.substr((s.length() + 1) / 2, (s.length() - 1) / 2)))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
        
    return 0;
}