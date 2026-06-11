#include<algorithm>
#include<iostream>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};


main(){
  int n;
  while(cin>>n && n){
    int pos[n][2];
    int maxx=0,maxy=0,minx=0,miny=0;
    pos[0][0]=0;//y
    pos[0][1]=0;//x
    REP(i,1,n){
      int tn,d;
      cin>>tn>>d;
      pos[i][0]=pos[tn][0]+dy[d];
      pos[i][1]=pos[tn][1]+dx[d];
      maxx=max(maxx,pos[i][0]);
      maxy=max(maxy,pos[i][1]);
      miny=min(miny,pos[i][1]);
      minx=min(minx,pos[i][0]);
    }
    cout << maxy-miny+1 <<" " << maxx-minx+1<< endl;
  }
}