#include<iostream>

using namespace std;

int main(){
  int a,b,c,k;
  cin >> a >> b >> c >> k;
  for(int i=0; i<k; i++){
    if(b <= a){
      b*=2;
    }else if(c <= a || c <= b){
      c*=2;
    }else{
      break;
    }
  }
  if(a < b && b < c){
      cout << "Yes" << endl;
      return 0;
  }else{
	cout << "No" << endl;
  	return 0;
  }
}