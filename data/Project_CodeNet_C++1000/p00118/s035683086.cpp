#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
string s[100];
char c[]={'#','*','@'};
int a,b,p,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void dfs(int y,int x){
  s[y][x]='.';
  r(i,4)
    if(x+dx[i]>=0&&dx[i]+x<b)
      if(y+dy[i]>=0&&dy[i]+y<a)
        if(s[y+dy[i]][x+dx[i]]==c[p])
        dfs(y+dy[i],x+dx[i]);
}
main(){
  while(cin>>a>>b,a){
    r(i,a)cin>>s[i];
    int su=0;
    r(i,a)r(j,b){
      if(s[i][j]!='.'){
        if(s[i][j]=='@'){p=2;dfs(i,j);};
        if(s[i][j]=='*'){p=1;dfs(i,j);};
        if(s[i][j]=='#'){p=0;dfs(i,j);};
        su++;
      }
    }
    cout<<su<<endl;
  }
}