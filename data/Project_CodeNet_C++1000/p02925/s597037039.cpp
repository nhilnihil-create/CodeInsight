#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int a[1005][1005],n;
int r[1005],d[1005];
bool v[1005];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        for(int j=0;j<n-1;++j) scanf("%d",a[i]+j);
    }
    int day = 1;bool update=true;
    for(int i=1;i<=n;++i)
        {r[i] = a[i][0];a[i][n-1]=-1;}

    int ans = 0;
    while(true)
    {
        update= false;
        for(int i=1;i<=n;++i){
            if(r[i]==-1) continue;
            if(v[i]){
                v[i] = false;continue;
            }
            if(r[i]>i&&!v[r[i]]&&i==r[r[i]]){

                update=true;
                v[r[i]] = true;
                if(d[i]+1<n)
                {
                    int rr = r[i];
                    r[i] = a[i][++d[i]];
                    r[rr] = a[rr][++d[rr]];
                }
            }
        }
        if(!update) break;
        ++ans;
    }
    for(int i=1;i<=n;++i){
        if(r[i]!=-1){
            ans = -1;break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
