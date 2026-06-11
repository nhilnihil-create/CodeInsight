#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int MAXN = 100005;
int a[MAXN];
void init()
{
    for(int y =  1;y<=MAXN-5;y++)
    {
        a[y] = y;
    }
}
int Find(int fa)
{
    if(fa==a[fa])
    {
        return a[fa];
    }
    else
    {
        return a[fa] = Find(a[fa]);
    }
}
int main()
{
    init();
    int n;
    int m;
    cin>>n>>m;
    int i = 0;
    for(int y = 1;y<=m;y++)
    {
        int l;int r;
        cin>>l>>r;
        int fa1 = Find(l);
        int fa2 = Find(r);
        if(fa1==fa2)
        {
            continue;
        }
        else
        {
            a[fa1] = fa2;
            i++;
        }
    }
    cout<<n-1-i<<endl;
    return 0;
}
