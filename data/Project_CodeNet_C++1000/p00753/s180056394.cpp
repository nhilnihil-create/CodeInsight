#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int num;
  while(cin>>num){
    if(num==0) break;
    int c = 0;
    for(int i=num+1;i <= 2*num;i++){
      bool f = true;
      for(int j=2;j<=sqrt(i);j++){
	if(i%j==0){
	  f = false;
	  break;
	}
      }
      if(f) c++;
    }
    cout<<c<<endl;
  }
  return 0;
}