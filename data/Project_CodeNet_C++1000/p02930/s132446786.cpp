#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
typedef long long ll;
const ll longinf=1LL<<60;
using namespace std;
int n;
int w[600][600];
int tag[600];

void dfs(int now, int tag_num)
{
    for (int i=now+1; i<=n; ++i)
    {
        if (w[now][i] == 0 && (tag[i]==0 || (tag[i] != tag[now])))
        {
            w[now][i] = w[i][now] = tag_num;
            if (tag[now] == 1)
                tag[i] = 2;
            else tag[i] = 1;
            dfs(i, tag_num);
        }
    }
}

int main()
{
    cin >> n;
    for (int i=1; i<=n; ++i)
    {
        memset(tag, 0, sizeof(tag));
        for (int j=1; j<=n; ++j)
        {
            if (tag[j] == 0)
            {
                tag[j] = 1;
                dfs(j, i);
            }
        }
    }
    for (int i=1; i<=n; ++i)
    {
        for (int j=i+1; j<=n; ++j)
            cout<<w[i][j]<<' ';
        cout<<endl;
    }


    return 0;
}

