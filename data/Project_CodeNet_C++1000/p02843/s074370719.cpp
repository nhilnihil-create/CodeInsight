#include <iostream>
#include <cmath>
using namespace std;

int main(){
  	int X, num, calc, cnt=0;
  	cin >> X;
  	num = X/100;
  	calc = X%100;
	while(calc>=5&&num>cnt){
    	calc-=5;
      	cnt++;
    }
  	while(calc>=4&&num>cnt){
    	calc-=4;
      	cnt++;
    }
  	while(calc>=3&&num>cnt){
    	calc-=3;
      	cnt++;
    }
  	while(calc>=2&&num>cnt){
    	calc-=2;
      	cnt++;
    }
  	while(calc>=1&&num>cnt){
    	calc-=1;
      	cnt++;
    }
  	while(calc==0&&num>cnt){
    	calc-=0;
      	cnt++;
    }
  	if(calc==0 && cnt==num){
    	cout << 1 << endl;
    }else{
    	cout << 0 << endl;
    }
	return 0;
}