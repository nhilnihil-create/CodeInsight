#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 5;
char g[10][10],g2[10][10];
int h,w,k,ans=0;

int main() {
    scanf("%d%d%d",&h,&w,&k);
    for(int i=0;i<h;i++){
        scanf("%s",g[i]);
    }
    for(int s=0;s<(1<<(h+w));s++){
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                g2[i][j]=g[i][j];
        for(int i=0;i<h;i++){
            if(s&(1<<i)){
                for(int j=0;j<w;j++)
                    g2[i][j]='r';
            }
        }
        for(int j=0;j<w;j++){
            if(s&(1<<(j+h))){
                for(int i=0;i<h;i++)
                    g2[i][j]='r';
            }
        }
        int cntb=0;
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                if(g2[i][j]=='#') cntb++;
        if(cntb==k) ans++;
    }
    printf("%d",ans);
    return 0;
}