#include <iostream>
using namespace std;

int main(){
  int a,cou;
  while(cin>>a){
    cou=0;
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
	for(int k=0;k<10;k++){
	  for(int q=0;q<10;q++){
	    if(i+j+k+q==a)cou++;
	  }
	}
      }
    }
    cout<<cou<<endl;
  }
  return 0;
}