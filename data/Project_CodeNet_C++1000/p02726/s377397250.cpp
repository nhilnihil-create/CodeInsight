#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n,x,y;
int dis[2010][2010];
int ans[2020];
int main(){
    //freopen("data.in","r",stdin);
    cin>>n>>x>>y;
    int len=y-x+1;
    for(int i=1;i<x;i++){
        for(int j=i+1;j<=n;j++){
            if(j<=x) dis[i][j]=j-i;
            else if(j>=y) dis[i][j]=j-i-(y-x)+1;
            else{
                int d2=min(j-x,y-j+1);
                dis[i][j]=x-i+d2;
            }
        }
    }
    for(int i=x;i<=y;i++){
        for(int j=x+1;j<=n;j++){
            if(j<=y){
                dis[i][j]=min(j-i,y-j+1+i-x);
            }
            else{
                dis[i][j]=min(y-i,i-x+1)+j-y;
            }
        }       
    }
    for(int i=y+1;i<=n;i++){
        for(int j=i+1;j<=n;j++)
            dis[i][j]=j-i;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans[dis[i][j]]++;
        }
    }   
    for(int i=1;i<n;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}