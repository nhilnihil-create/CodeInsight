#include<iostream>
using namespace std;

int main(){
  while(1){
    int h,h1,w,w1,a,b,min=100000000;
    cin>>h>>w;
    if(h+w==0)break;
    a=h*h+w*w;

    for(int i=1;i<=150;i++)
      for(int j=i+1;j<=150;j++){
	b=i*i+j*j;
	if(b>a || (b==a && h<i))
	  if(min>b){
	    min=b;
	    h1=i;
	    w1=j;
	  }
      }
    cout<<h1<<' '<<w1<<endl;
  }

  return 0;
}