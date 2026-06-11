#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    if(s[2] == s[3] && s[4] == s[5])
        cout << "Yes";
    else
        cout << "No";
}
