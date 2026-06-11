#include<bits/stdc++.h>
using namespace std;
#define f(n) for(int i=0; i<n; i++)
#define endl '\n'
#define ll long long

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    cin >> s;

    cout << ( s[2] == s[3] && s[4] == s[5] ? "Yes" : "No");

    return 0;
}


