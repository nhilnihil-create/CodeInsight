#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    int res = 0;
    for(int i = 0; i < n / 2; ++i)
    {
        if(s[i] != s[n - i - 1])
            res++;
    }
    cout << res << "\n";
    return 0;
}