#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
int N,M;
int fie[21][21];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
map<char,int> m;
main(){
  m['N']=0;
  m['E']=1;
  m['S']=2;
  m['W']=3;
  while(1){
    scanf("%d",&N);
    if(N==0) break;
    memset(fie,0,sizeof(fie));
    for(int i=0;i<N;i++){
      int x,y;
      //      scanf("%d %d",&x,&y);
      cin >> x >> y;
      fie[x][y]=1;
    }
    fie[10][10]=0;
    scanf("%d",&M);
    int X=10,Y=10;
    for(int i=0;i<M;i++){
      char d;
      int o;
      cin >> d >> o;
      for(int j=0;j<o;j++){
	X+=dx[m[d]];
	Y+=dy[m[d]];
	//	cout << X << " " << Y << ":"<<fie[X][Y]<<endl;
	fie[X][Y]=0;
      }
    }
    
    bool f=true;
    for(int i=0;i<21;i++)
      for(int j=0;j<21;j++)
	if(fie[j][i]) f=false;
    if(f) puts("Yes");
    else puts("No");
  }
}