#include<iostream>
using namespace std;

int main(){
  int i,n,m,p,x[1001],total;


  while(1){
         
    total = 0;
    cin >> n >> m >> p;
    if(n==0 && m==0 && p==0)break;

    for( i = 1; i <=1000; i++){
      x[i]=0;
    }

    for( i = 1; i <= n; i++){
      cin >> x[i];
      total += x[i]*100;
    }
      
    if(x[m]>0){
      total = total * (100- p) /100;
      total /= x[m];
      cout << total << endl;
    }else if(x[m]==0){
      cout << 0 << endl;
    }
  }
  return 0;
}