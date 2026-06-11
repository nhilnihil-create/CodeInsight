#include<iostream>
using namespace std;
int main(){
  int money,bell;
  while(1){
    cin >> money;
    if(money==0){
      break;
    }
    money=1000-money;
    bell=0;
    while(money!=0){
      if(money>=500){
	bell++;
	money-=500;
      }
      else if(money>=100){
	bell++;
	money-=100;
      }
      else if(money>=50){
	bell++;
	money-=50;
      }
      else if(money>=10){
	bell++;
	money-=10;
      }
      else if(money>=5){
	bell++;
	money-=5;
      }
      else if(money>=1){
	bell++;
	money-=1;
      }
    }
    cout << bell << endl;
  }
}