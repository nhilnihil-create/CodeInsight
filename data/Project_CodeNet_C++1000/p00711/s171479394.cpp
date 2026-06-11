#include <iostream>
using namespace std;
int a=0;
int box[22][22]={{}};
int  kazoe(int p,int P,int H,int W){
  int i,I;
  a++;
  box[p][P]=0;
  if(box[p][P+1]==1) kazoe(p,P+1,H,W);
  if(box[p][P-1]==1) kazoe(p,P-1,H,W);
  if(box[p-1][P]==1) kazoe(p-1,P,H,W);
  if(box[p+1][P]==1) kazoe(p+1,P,H,W);
  else {
  return a;
  }
}
int main(){
  int i,I,H,W,p,P;
  
  char v;
  while(1){
  cin>>W>>H;
  for(i=0;i<=H+1;i++){
    for(I=0;I<=W+1;I++){
      box[i][I]=0;
    }
  }
  if(W==0&&H==0) break;
  for(i=1;i<=H;i++){
    for(I=1;I<=W;I++){
      cin>>v;
      if(v=='.') box[i][I]=1;
      if(v=='#') box[i][I]=2;
      if(v=='@') {
	box[i][I]=0;
	p=i;
	P=I;
      }
    }
  }
  cout<<kazoe(p,P,H,W)<<endl;
  a=0;
  }
  return 0;
}