#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
//vector<int>G[MAXN];
//int dis[MAXN][MAXN];
int ans[MAXN]={0};
int main()
{
    //memset(dis,1,sizeof dis);
    int n;
    int x,y;
    cin >> n >> x >> y;
    //dis[x][x]=0;
    //dis[y][y]=0;
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;j++){
            int num = j-i;
            num = min(num,abs(i-x)+abs(j-y)+1);
			num=min(num,abs(i-y)+abs(j-x)+1);
            ans[num]++;
        }
        //    dis[i][j]=dis[j][i]=j-i;
    }
//    for(int i=1;i<=x;++i){
//        for(int j=y;j<=n;++j)
//            dis[i][j]=dis[j][i]=dis[i][x]+dis[y][j]+1;
//    }
//    for(int i=n-1;i>0;i--){
//
//        if(i<=x){
//
//        }
//        else if(i>=y){
//            for(int j=1;j<=x;j++){
//                dis[i][j]=dis[j][i]=dis[i][y]+dis[x][j]+1;
//            }
//        }
//        else{
//
//        }
//        for(int j=i+1;j<=n;j++){
//            ans[dis[i][j]]++;
//        }
//    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++)
//            cout << dis[i][j] << " \n"[j==n];
//
//    }
    for(int i=1;i<n;i++){
        cout << ans[i] << endl;
    }
    return 0;
}
