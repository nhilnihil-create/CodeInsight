#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    char c = 'B';
    string s;
    cin >> s;
    if(s[1]=='B') c = 'R';
    s[1] = c;
    cout << s << '\n';
    return 0;
}