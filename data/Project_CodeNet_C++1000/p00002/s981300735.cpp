#include<iostream>

using namespace std;

int main(){

	int  a, b,c, counter= 1, sum=1;

	while(cin >> a>>b){ 
		sum=a+b;
		
		while(sum/10!=0){
			sum=sum/10;
			counter++;
		}
		
		cout<<counter<<endl;

		counter=1;
		
		

	}

}