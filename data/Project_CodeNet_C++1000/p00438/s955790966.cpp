#include<iostream>
#include<stdlib.h>
using namespace std;

int a,b,cnt;
int* p;

void rec(int x,int y){
  if(x==a-1&&y==b-1){cnt++;return;}
  if(x<a-1&&p[(x+1)+y*a]==0)rec(x+1,y);
  if(y<b-1&&p[x+(y+1)*a]==0)rec(x,y+1);
}

int main () {
  while(cin>>a>>b,a|b){
    cnt=0;
    int d[a*b]={};p=d;int k;cin>>k;
    for(int i=0;i<k;++i){
      int x,y;cin>>x>>y;x--;y--;
      d[x+y*a]=1;
    }
    rec(0,0);
    cout<<cnt<<endl;
  }
}