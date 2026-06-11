#include<iostream>
#include <bits/stdc++.h>
#include<algorithm>
#include <cstring>
#define endl "\n"
#define SRK ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define EPS 1e-6
#define MAX 100000
typedef long long ll;
const ll MOD = 1e9 + 7;
using namespace std;

int main()
{
    string s;
    cin >> s;
    if ((s[2] == s[3]) &&(s[4] == s[5]))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

}
