#include<iostream>
using namespace std;
void counts(int h,int w);
int check[121][121]={0};
char s[121][121];
int dh[4]={-1,0,1,0};
int dw[4]={0,1,0,-1};
int ww,hh;
int counta=0;
char now;
main(){
  int sw,sh,countx;
  while(1){
    cin>>hh>>ww;
    if(ww==0&&hh==0) break;
    for(int i=1;i<=hh;i++){
      for(int j=1;j<=ww;j++){
	cin>>s[i][j];
      }
    }
    for(int i=1;i<=hh;i++){
      for(int j=1;j<=ww;j++){
	if(check[i][j]==0){
	  now=s[i][j];
	  counts(i,j);
	  counta++;
	  //cout<<endl;
	}
      }
    }
    cout<<counta<<endl;
    for(int i=0;i<=120;i++){
      for(int j=0;j<=120;j++){
	check[i][j]=0;
      }
    }
    counta=0;
  }
}
void counts(int h,int w){
  check[h][w]=1;
  //cout<<"check="<<h<<" "<<w<<"| ";
  for(int i=0;i<4;i++){
    int nh=h+dh[i];
    int nw=w+dw[i];
    if(nh>=1&&nh<=hh&&nw>=1&&nw<=ww&&s[nh][nw]==now&&check[nh][nw]==0){
      counts(nh,nw);
    }
  }
  return;
}