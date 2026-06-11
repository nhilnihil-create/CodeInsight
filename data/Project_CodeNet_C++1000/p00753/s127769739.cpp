#include<iostream>
#include<cmath>
using namespace std;


int main(){
  int n,count=0;
  bool flag=false;
  while(true){
    cin >>n;
    if(n==0) break;

    count=2*n-n;
    for(int i=2*n;i>n;i--){ 
      for(int j=2;j<=sqrt(i);j++){
	if(i%j==0){
	  count--;
	  //cout <<"not "<<i<<endl;
	  break;
	}
      }
    }
    cout <<count<<endl;
  }
  return 0;
}