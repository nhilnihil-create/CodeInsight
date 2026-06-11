#include<bits/stdc++.h>
using namespace std;
int main(){
  int W,H,X,Y;
  cin>>W>>H>>X>>Y;
  double ans=(double)W*H/2;
  int num;
  if(W==X*2&&H==Y*2){
    num=1;
  }
  else{
    num=0;
  }
  printf("%.10f %d\n",ans,num);
}
