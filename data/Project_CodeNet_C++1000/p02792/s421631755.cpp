#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    map<pair<int, int>, int> fl;
    for (int i = 1; i <= n; i++)
    {
        int f = -1, l = i % 10;
        for (int j = 10;; j *= 10)
        {
            if (i >= 10)
                f = i / j;
            else
                f = i;
            if (f < 10)
                break;
        }
        ans += fl[make_pair(l, f)] * 2;
        if (f == l)
            ans += 1;
        fl[make_pair(f, l)]++;
    }
    cout << ans << endl;
}
