#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int maxd = (1<<19)+10;
int arr[maxd],n,m,que[maxd],p;
multiset<int> s;
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("k.out","w",stdout);
    scanf("%d",&n);m = 1 << n;
    for(int i=1;i<=m;i++) scanf("%d",&arr[i]);
    sort(arr+1,arr+1+m,cmp);
    for(int i=2;i<=m;i++) s.insert(-arr[i]);
    s.insert(1); que[++p] = -arr[1];
    int now = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=now;j++)
        {
            set<int>::iterator it;
            it = s.upper_bound(que[j]);
            //printf("%d %d\n",que[j],*it);
            if(*it==1)
            {
                printf("No\n");
                return 0;
            }
            que[++p] = *it;
            s.erase(it);
        }
        now*=2;
    }
    printf("Yes\n");
    return 0;
}