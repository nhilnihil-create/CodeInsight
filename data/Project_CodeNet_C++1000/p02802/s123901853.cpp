#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> ac(n), wa(n);
    int AC = 0, WA = 0;
    rep(i, m)
    {
        int p;
        string s;
        cin >> p >> s;
        p--;
        if (s == "AC")
        {
            if (ac[p] == 1)
                continue;
            AC++;
            WA += wa[p];
            ac[p]++;
        }
        else
        {
            wa[p]++;
        }
    }
    cout << AC << " " << WA << endl;
    return 0;
}