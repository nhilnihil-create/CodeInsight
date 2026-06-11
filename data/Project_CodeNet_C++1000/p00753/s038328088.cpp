#include<iostream>
#include<cmath>
using namespace std;

int cnt;

void chev(int n){
  int f=1;
  for(int i=n+1;i<=2*n;i++){
    f=1;
    for(int j=2;j<=sqrt(i);j++){
      if(i%j==0)f=0;
    }
    if(f)cnt++;
  }
}

int main(){
  while(1){
    cnt=0;
    int n;
    cin >> n;
    if(n==0)break;
    chev(n);
    cout << cnt <<endl;
  }
}