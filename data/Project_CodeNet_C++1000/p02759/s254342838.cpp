#include <iostream>
using namespace std;

int main(){
	int n;
  	cin>>n;
  
  	int cnt=0;
  	cnt=n/2;
  	if(n%2==1){
    	cnt++;
    }
  
  	cout<<cnt<<endl;
}