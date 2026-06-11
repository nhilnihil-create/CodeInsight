#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//MJC *start on @date: 2020-09-13 20:13 
using namespace std;
typedef long long ll;

struct node
{
    int c;  //价格
    int a[15];  //提升的等级
}book[15];   //每本书

int b[15];  //提升某个算法的总等级数

int main()
{
    int n,m,x;
    cin>>n>>m>>x;
    for (int  i=0; i < n; i++)
    {
        cin>>book[i].c;
        for (int  j = 0; j<m; j++)
            cin>>book[i].a[j];  
    }
    int ans=2e9;
    for (int  i = 0;i<(1<<n); i++)
    {
        memset(b,0,sizeof b);
        int sum=0;
        for(int j=0;j < n;j++)
            if(i>>j&1){
                sum+=book[j].c;
                for(int k=0; k < m; k++) 
                    b[k]+=book[j].a[k];
            }
        bool flag=1;
        for (int  j = 0; j < m; j++)
            if(b[j] < x)
                flag=0;
        if(flag) 
            ans=min(ans,sum);
    }
    if(ans==2e9) 
        cout<<"-1";
    else
        cout<<ans;
    return 0;
}