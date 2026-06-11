#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define ll long long
using namespace std;

int h,w,k,x[10],y[10],ans,bl;
char c[10][10];

void dfs(int num,int opt,int sum){
    if (sum<k) return;
    if (opt==1){
        if (num==w){
            ans+=(sum==k);
            return;
        }
        dfs(num+1,opt,sum);
        int q[10];q[0]=0;

        for (int i=0;i<h;++i)
            if (c[i][num]=='#') q[++q[0]]=i,c[i][num]='.',--sum;
        dfs(num+1,opt,sum);
        for (int i=1;i<=q[0];++i)
            c[q[i]][num]='#',++sum;
    }
    else {
        if (num==h){
            dfs(0,1,sum);
            return;
        }
        dfs(num+1,opt,sum);

        int q[10];q[0]=0;
        for (int i=0;i<w;++i)
            if (c[num][i]=='#') q[++q[0]]=i,c[num][i]='.',--sum;
        dfs(num+1,opt,sum);
        for (int i=1;i<=q[0];++i)
            c[num][q[i]]='#',++sum;
    }

}

int main() {
    scanf("%d%d%d",&h,&w,&k);
    for (int i=0;i<h;++i) {
        scanf("%s", c[i]);
        for (int j=0;j<w;++j)
            if (c[i][j]=='#') ++bl;
    }
    dfs(0,0,bl);
    printf("%d\n",ans);
    return 0;
}
