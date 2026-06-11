#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
class ans
{
public:
    int a,i;
};
vector<int> cn[10001];
int chk[10001],now=1;
ans num[10001];
int dfs(int n)
{
    if(chk[n]>0) return 0;
    int tmp=cn[n].size();
    for(int i=0;i<tmp;i++)
    {
        dfs(cn[n][i]);
    }
    chk[n]=now++;
    return 0;
}
bool cmp(ans a,ans b)
{
    return a.i>b.i;
}
int main()
{
    int v,e,x,y;
    scanf("%d%d",&v,&e);
    for(int i=0; i<=v; i++)
    {
        num[i].a=i;
    }
    for(int i=0; i<e; i++)
    {
        scanf("%d%d",&x,&y);
        cn[x].push_back(y);
    }
    for(int i=0; i<v; i++)
    {
        if(chk[i]==0)
        {
            dfs(i);
        }
    }
    for(int i=0; i<v; i++) num[i].i=chk[i];
    sort(num,num+v,cmp);
    for(int i=0; i<v; i++) printf("%d\n",num[i].a);
    return 0;
}