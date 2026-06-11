#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=1000000+10;
int n;
int a[maxn];
vector<int> g;
int cnt;
void insert_sort(int a[],int n,int g)
{
    for(int i=g;i<n;i++)
    {
        int key=a[i];
        int j=i-g;
        while(j>=0&&a[j]>key)
        {
            a[j+g]=a[j];
            j-=g;
            cnt++;
        }
        a[j+g]=key;
    }
}
void shell_sort(int a[],int n)
{
    int h=0;
    while(true)
    {
        h=3*h+1;
        if(h>n) break;
        g.push_back(h);
    }
    int len=g.size();
    for(int i=len-1;i>=0;i--)
    {
        insert_sort(a,n,g[i]);
    }

}

int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    cnt=0;
    shell_sort(a,n);
    int len=g.size();
    printf("%d\n",len);
    for(int i=len-1;i>=0;i--)
    {
        if(i!=len-1) printf(" ");
        printf("%d",g[i]);
    }
    printf("\n");
    printf("%d\n",cnt);
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }

    return 0;
}