#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int n;
void search(vector<vector<int> > &G1, vector<vector<int> > &G2, int *d, bool *v)
{
    int mini, minv;
    while (1)
    {
        bool iscomp = true;
        minv = INFTY;
        rep(i, 0, n)
        {
            if (!v[i] && d[i] < minv)
            {
                mini = i;
                minv = d[i];
                iscomp = false;
            }
        }
        if (iscomp)
            break;
        v[mini] = true;
        rep(i, 0, G1[mini].size())
        {
            int tmp = G1[mini][i];
            if (!v[tmp])
            {
                int tmptime = minv + G2[mini][i];
                if (tmptime < d[tmp])
                    d[tmp] = tmptime;
            }
        }
    }
}
int main()
{
    cin >> n;
    vector<vector<int> > G1(n, vector<int>(0)), G2(n, vector<int>(0));
    int d[n];
    bool v[n] = {};
    rep(i, 0, n) d[i] = INFTY;
    int utmp, ktmp, vtmp, ctmp;
    rep(i, 0, n)
    {
        cin >> utmp >> ktmp;
        rep(j, 0, ktmp)
        {
            cin >> vtmp >> ctmp;
            G1[utmp].push_back(vtmp);
            G2[utmp].push_back(ctmp);
        }
    }
    d[0] = 0;
    search(G1, G2, d, v);
    rep(i, 0, n)
    {
        printf("%d %d\n", i, d[i]);
    }
}
