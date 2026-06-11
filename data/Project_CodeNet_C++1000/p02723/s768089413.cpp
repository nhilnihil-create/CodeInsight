#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_in_out  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    fast_in_out;
    string s;
    cin >> s;
    if(s[2] == s[3] && s[4] == s[5])
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
