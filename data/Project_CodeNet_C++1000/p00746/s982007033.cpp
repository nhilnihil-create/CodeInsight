#include<iostream>
using namespace std;
int main(){
  int n,m,d,dy[4]={0,-1,0,1},dx[4]={-1,0,1,0},y,x;
  while(1){
    cin>>n;if(n==0)break;
    int mp[401][401];
    for(int i=0;i<401;i++)for(int j=0;j<401;j++)mp[i][j]=-1;
    mp[200][200]=0;
    for(int i=1;i<n;i++){
      cin>>m>>d;
      for(int j=0;j<401;j++)
	for(int k=0;k<401;k++)
	  if(mp[j][k]==m)mp[j+dy[d]][k+dx[d]]=i;
    }
    n=m=400,x=y=0;
    for(int i=0;i<401;i++)
      for(int j=0;j<401;j++)
	if(mp[i][j]!=-1){
	  if(i<m)m=i;
	  if(j<n)n=j;
	  if(i>y)y=i;
	  if(j>x)x=j;
	}
    cout<<x-n+1<<" "<<y-m+1<<endl;
  }
  return 0;
}