#include<iostream>
using namespace std;

int Hurui(int n){

  bool flg[123456*2];
  int sum=0;
  int head;
  for(int i=0; i<n; i++){
    flg[i]=false;
  }

  head=2;
  while(head<=n){

    if(head > n/2){ sum++; }

    for(int i=1; i*head<=n; i++ ){
      flg[i*head -1]=true;
    }

    while(flg[head-1]==true && head<=n){
      head++;
    }

  }

  return sum;

}

int main(){

  int n;

  while(cin >> n){
    if(n==0){ break; }

    cout << Hurui(n*2) << endl;

  }


  return 0;
}