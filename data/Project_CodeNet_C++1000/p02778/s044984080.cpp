#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    fast_io;
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0 ; i < n; i++)
    {
        char c = 'x';
        s[i] = c;
    }
    cout << s;
}
