#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    string s[2];
    string c;
    ll n[2];

    cin >> s[0] >> s[1];
    cin >> n[0] >> n[1];
    cin >> c;

    if (c==s[0]) {
        cout << n[0] - 1 << " " << n[1];
    } else {
        cout << n[0] << " " << n[1] - 1;
    }
}