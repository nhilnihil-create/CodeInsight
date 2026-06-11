#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
struct st{
    int n;
    int index;
}a[100010];
bool cmp(st a,st b)
{
    return a.n < b.n;
}
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].n;
        a[i].index = i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        cout << a[i].index << " ";
    }
    return 0;
}