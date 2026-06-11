#include<iostream>
#include<cstdio>
using namespace std ;
int main(){
  int W,H;
  for( ; ; ){
    cin >> H >> W; 
    if(H==0 && W==0)break;
    for(int i=0;i<H;i++){
      for(int k=0;k<W;k++){
	if(i>0 && H-1>i && W-1>k && k>0){
	  printf(".");
	}else{
	  printf("#");
	} 
      }
    cout<<endl;
    }
cout<<endl;
  }

  return 0;
}