#include <bits/stdc++.h>

using namespace std;

set<pair<int, int>> s;

int hcnt[300100], wcnt[300100];
int maxh, maxw;
vector<int> posh, posw;

int main()
{
    int H, W, m;
    scanf("%d%d%d", &H, &W, &m);
    for(int i = 1; i <= m; ++i)
    {
        int h, w;
        scanf("%d%d", &h, &w);
        hcnt[h]++;
        wcnt[w]++;
        maxh = max(maxh, hcnt[h]);
        maxw = max(maxw, wcnt[w]);
        s.insert({h, w});
    }
    for(int h = 1; h <= H; ++h)
        if(maxh == hcnt[h]) posh.push_back(h);
    for(int w = 1; w <= W; ++w)
        if(maxw == wcnt[w]) posw.push_back(w);
    for(int h : posh)
        for(int w : posw)
            if(!s.count({h, w}))
            {
                printf("%d\n", maxh + maxw);
                return 0;
            }
     printf("%d\n", maxh+maxw-1);
}
