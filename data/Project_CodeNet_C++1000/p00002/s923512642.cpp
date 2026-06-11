#include<iostream>

using namespace std;

int main(){
	
	int i;

	int a,b,sum,figure;

	while(cin >> a >> b){
		sum = a + b;
		figure = 1;
		while(sum/10!=0){
			sum = sum/10;
			figure++;
		}
		cout << figure << "\n";
	}	
	return 0;
}