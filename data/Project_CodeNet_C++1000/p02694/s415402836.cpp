#include<iostream>

using namespace std;

int main() {
	long long mon=101,X,y=0;
  	cin>>X;
  	if(mon>=X){}    
    else{y++;}
  	while(mon<X){
    	mon+=mon/100;
      	y++;
    }
  	cout<<y<<endl;
}