#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
struct Node{
    int index, number;
}a[N];
int n;

bool cmp(const Node &x,const Node &y)
{
    return x.number < y.number;
} 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].number);
        a[i].index = i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i].index);
    }
    printf("\n");
    return 0;
}