#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
char s[30005];
int pre[30005][11]={0};
int suf[30005][11]={0};
int vis[1005]={0};
void solve(int dd,int num){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(pre[dd-1][i]&&suf[dd+1][j]){
                vis[i*100+num*10+j]=1;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i++){
        if(i)
        for(int j=0;j<10;j++)
            pre[i][j]=pre[i-1][j];
        pre[i][s[i]-'0']++;
        //for(int j=0;j<10;j++)
       //     cout << pre[i][j] << " \n"[j==9];
    }
    for(int i=n-1;i>0;i--){
        
        for(int j=0;j<10;j++)
            suf[i][j]=suf[i+1][j];
        suf[i][s[i]-'0']++;
        //for(int j=0;j<10;j++)
        //    cout << suf[i][j] << " \n"[j==9];
    }
    for(int i=1;i<=n;i++){
        solve(i,s[i]-'0');
    }
    int ans = 0 ;
    for(int i=0;i<1000;i++){
        if(vis[i]){
           // cout << i << endl;
            ans++;
        }
            
    }
    cout << ans <<endl;
    return 0;
}
