#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    map<string, bool> mp;
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
      cin >> s;
      mp[s] = true;
    }
    cout << mp.size() << endl;
}