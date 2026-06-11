#include <bits/stdc++.h>

using namespace std;

int main()
{
    int g[3][3];
    for (int i = 0; i < 3; i++)
        cin >> g[i][0] >> g[i][1] >> g[i][2];

    int n;
    cin >> n;
    set<int> cj;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        cj.insert(b);
    }

    bool can = (cj.count(g[0][0]) > 0 && cj.count(g[1][1]) > 0 && cj.count(g[2][2]) > 0) ||
                (cj.count(g[0][2]) > 0 && cj.count(g[1][1]) > 0 && cj.count(g[2][0]) > 0);

    for (int i = 0; i < 3; i++) {
        if (cj.count(g[i][0]) > 0 && cj.count(g[i][1]) > 0 && cj.count(g[i][2]) > 0)
            can = true;
        else if (cj.count(g[0][i]) > 0 && cj.count(g[1][i]) > 0 && cj.count(g[2][i]) > 0)
            can = true;
    }
    if (can)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}