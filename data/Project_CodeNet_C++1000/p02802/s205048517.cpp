#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    int n, m, flag[100001] = {0}, cor = 0, pen = 0, tmp[100001] = {0};
    cin >> n >> m;
    rep(i, m)
    {
        int p;
        string s;
        cin >> p >> s;
        if (flag[p] == 0)
        {
            if (s.compare("WA") == 0)
                tmp[p]++;

            else
            {
                flag[p] = 1;
                pen += tmp[p];
                cor++;
            }
        }
    }
    cout << cor << " " << pen << endl;
    return 0;
}