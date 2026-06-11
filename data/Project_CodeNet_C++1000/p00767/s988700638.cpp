#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=1;i<n;i++)
#define lpin(a,i,n) for(int i=0;i<n;i++){cin>>a[i];}

int main(){
  int a[151][151];
  lp(i,151){
    lp(j,151){
      if(i>=j) a[i][j]=-1;
      else a[i][j]=i*i+j*j;
    }
  }
  while(1){
    int h,w;
    cin>>h>>w;
    if(h==0&&w==0) break;
    int x=h*h+w*w,min=1000000,minh,minw;
    lp(i,150){
      lp(j,150){
	if(a[i][j]==-1) 1;
	else if(a[i][j]-x>0 || x-a[i][j]==0 && i>h){
	  if(min>a[i][j]){
	    min=a[i][j];
	    minh=i;
	    minw=j;
	  }
	}
      }
    }
    cout<<minh<<" "<<minw<<endl;
  }
  
  return 0;
}

