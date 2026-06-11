#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e12

int const N = 1e3+5;

int main ()
{
    string s; cin >> s;
    bool playable = true;
    for (int i = 0; i < s.size() && playable; i++)
    {

        if (s[i] == 'U' || s[i] == 'D')
            continue;

        if (i%2 == 1 && s[i] == 'L')// even
            continue;

        if (i%2 == 0 && s[i] == 'R')
            continue;

        playable = false;
    }
    cout << (playable ? "Yes" : "No") << endl;
    return 0;
}
