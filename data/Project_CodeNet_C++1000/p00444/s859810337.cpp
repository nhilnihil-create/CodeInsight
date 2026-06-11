#include<iostream>
using namespace std;

int main(){
	for(int i=0; i<5; i++){

		int C;
		
		cin >> C ;


		cout << (1000-C)/500 + (1000-C)/100-5*((1000-C)/500) + 
				(1000-C)/50-2*((1000-C)/100) + (1000-C)/10-5*((1000-C)/50) +
				(1000-C)/5-2*((1000-C)/10) + (1000-C)-5*((1000-C)/5) << endl;
	}



}
