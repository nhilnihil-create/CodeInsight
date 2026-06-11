#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
#define mk make_pair
using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int main(){
  int h,w,n,sum=0,x1,y1;
  cin>>h>>w>>n;
  string s[h];
  for(int i=0;i<h;i++)cin>>s[i];
  r(i,h)r(j,w)if(s[i][j]=='S')y1=i,x1=j;
  for(int o=1;o<=n;o++){
    int used[h][w]={};
    queue<pair<pair<int,int>,int> >q;
    q.push(mk(mk(y1,x1),0));
    used[y1][x1]=1;
    while(!q.empty()){
      pair<pair<int,int>,int> p=q.front();q.pop();
      int x=p.first.second,y=p.first.first,sum2=p.second;
      if(s[y][x]-'0'==o){
        sum+=sum2;
        y1=y;
        x1=x;
        goto L;
      }
      r(j,4){
        int xx=x+dx[j],yy=y+dy[j];
        if(xx>=0&&yy>=0&&yy<h&&xx<w)
          if(!used[yy][xx])
            if(s[yy][xx]!='X'){
              q.push(mk(mk(yy,xx),sum2+1));
              used[yy][xx]++;
            }
      }
    }L:;
  }
  cout<<sum<<endl;
}