#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>

int v,e,in[10005];
std::queue<int> q;
std::vector<int> g[10005];

int main()
{
    scanf("%d%d",&v,&e);
    while(e--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        in[y]++;
    }
    for(int i=0;i<v;i++)
        if(!in[i])
            q.push(i);
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        printf("%d\n",now);
        for(std::vector<int>::iterator it=g[now].begin();it!=g[now].end();it++)
            if(!--in[*it])
                q.push(*it);
    }
    return 0;
}
