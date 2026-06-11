#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(void)
{
    string s;
    cin >> s;
    map<char,int> mp;
    rep(i, 4) mp[s[i]]++;
    int answer = 1;
    for(auto m : mp) if (m.second != 2) answer = 0;
    if (answer) cout << "Yes" << endl;
    else cout << "No" << endl;

}
