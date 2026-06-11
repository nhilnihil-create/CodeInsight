#include<iostream>
#include<cstring>
using namespace std;
#define maxn 110
#define INFTY (1<<30)
#define WHITE 0
#define GRAY 1
#define BLACK 2
int n,m[maxn][maxn];

int prim() //返回最小生成树各边权值总和
{
    int u,minv;
    int d[maxn],p[maxn],color[maxn];

    for(int i=0;i<n;i++) //初始化
    {
        d[i]=INFTY;
        p[i]=-1;
        color[i]=WHITE;
    }
    d[0]=0;

    while(1)
    {
        minv=INFTY;
        u=-1;
        for(int i=0;i<n;i++)
        {
            if(minv>d[i]&&color[i]!=BLACK) //寻找最小权值的边
            {
                u=i;
                minv=d[i];
            }
        }
        if(u==-1) break;
        color[u]=BLACK; //标记为黑
        for(int v=0;v<n;v++)
        {
            if(color[v]!=BLACK&&m[u][v]!=INFTY) //如果u和v之间存在边
            {
                if(m[u][v]<d[v]) //注意这里是d[v]不是d[u]
                {
                    d[v]=m[u][v];
                    p[v]=u;
                    //color[v]=GRAY;
                }
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
        if(p[i]!=-1) sum+=m[i][p[i]];
    return sum;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>m[i][j];
            if(m[i][j]==-1) m[i][j]=INFTY;
        }
    }
    cout<<prim()<<endl;
    return 0;
}
