#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    bool eq = 1;
    string s,t;
    cin >> s >> t;
    int n = s.size();
    for(int i=0;i<n;i++) if(s[i]!=t[i]) eq = 0;
    cout << (eq ? "Yes":"No") << '\n';
    return 0;
}