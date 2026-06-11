#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector<pii> e;
void addedge(int a,int b)
{
    e.emplace_back(a,b);
}
int main()
{
    int n;scanf("%d",&n);
    if(n<3||(n-(n&-n))==0)printf("No\n");
    else{
        printf("Yes\n");
        addedge(1,2),addedge(2,3),addedge(3,n+1);
        addedge(1,3+n),addedge(3+n,2+n);
        for(int i=4;i+1<=n;i+=2)
            addedge(1,i),addedge(i,i+1),addedge(1,i+1+n),addedge(i+1+n,i+n);
        if(!(n&1))
        {
            int k=(n-1)^n;
            addedge(k+n,n),addedge(n-2,n*2);
        }
        for(pii p:e)printf("%d %d\n",p.first,p.second);
    }
}