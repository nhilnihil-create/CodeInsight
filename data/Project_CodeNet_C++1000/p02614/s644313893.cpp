#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <functional>
#include <vector>
#include <stack>
#include <set>
#include <bitset>
using namespace std;
typedef  long long ll;
const int maxn=1e6+50;
const int inf=0x3f3f3f3f;
const int MOD=1e9+7;
const int HASH=131;

int a[10][10];
int n,m,k;
int ans=0;
string s;

bool jungle(int row[],int line[])//row line 1代表涂色，0没涂色
{
    int num=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(row[i]==0&&line[j]==0&&a[i][j]==0)  num++;
        }
    }
    if(num==k)
    {
//        printf("*************************\n");
//        printf("row:");
//        for(int i=1;i<=n;i++)
//        printf(" %d",row[i]);
//        printf("\nline:");
//        for(int i=1;i<=m;i++)
//        printf(" %d",line[i]);
//        printf("\n");
        return true;
    }
    else return false;
}


int main()
{
    cin>>n>>m>>k;
    int row[10];
    int line[10];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char tmp;
            cin>>tmp;
            if(tmp=='.') a[i][j]=1;
            else {a[i][j]=0;}
        }
    }
    int r=1,l=1;
    for(int i=1;i<=n;i++)
        r*=2;
    for(int i=1;i<=m;i++)
        l*=2;
    for(int i=0;i<=r;i++)
    {
        bitset<6> t(i-1);
        s=t.to_string();
        for(int j=0;j<n;j++)
        {
            row[j+1]=s[6-n+j]-'0';
        }
        for(int j=0;j<=l;j++)
        {
            bitset<6> tt(j-1);
            s=tt.to_string();
            for(int k=0;k<m;k++)
            {
                line[k+1]=s[6-m+k]-'0';
            }
            if(jungle(row,line)) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
