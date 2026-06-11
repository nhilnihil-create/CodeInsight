#include<iostream>
using namespace std;
void counts(int h,int w);
int check[31][31]={0};
char s[31][31];
int dh[4]={-1,0,1,0};
int dw[4]={0,1,0,-1};
int ww,hh;
int counta=0;
main(){
  int sw,sh,countx;
  while(1){
    cin>>ww>>hh;
    if(ww==0&&hh==0) break;
    for(int i=1;i<=hh;i++){
      for(int j=1;j<=ww;j++){
	cin>>s[i][j];
	if(s[i][j]=='@'){
	  sh=i;
	  sw=j;
	}
      }
    }
    counts(sh,sw);
    cout<<counta<<endl;
    for(int i=0;i<=30;i++){
      for(int j=0;j<=30;j++){
	check[i][j]=0;
      }
    }
    counta=0;
  }
}
void counts(int h,int w){
  check[h][w]=1;
  counta++;
  for(int i=0;i<8;i++){
    int nh=h+dh[i];
    int nw=w+dw[i];
    if(nh>=1&&nh<=hh&&nw>=1&&nw<=ww&&s[nh][nw]=='.'&&check[nh][nw]==0){
      counts(nh,nw);
    }
  }
  return;
}