#include<iostream>
#include<cstdio>
using namespace std;

int h,w;
int hw;
int tai;
int cheak;
int mn;
int high,wide;

main(){
  while(cin >> h >> w,h||w){
    hw=h*h+w*w;
    tai=-1;
    mn=0;
    for(int i=1;i<=150 && mn==0;i++){
      cheak=0;
      for(int j=i+1;j<=150 && cheak==0;j++){
        if(hw<i*i+j*j && (tai==-1 || tai>i*i+j*j)){
          tai=i*i+j*j;
          high=i;
          wide=j;
        }
        else if(hw==i*i+j*j && i>h){
          high=i;
          wide=j;
          cheak=1;
          mn=1;
        }
      }
    }
    cout << high << " " << wide << endl;

  }
}