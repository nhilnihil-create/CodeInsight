#include <iostream>
#include <vector>
using namespace std;

int main(){
	
	long long x;
	long long y=100,z = 0;
	cin >> x;
	
	while(x > y){
		y += y/100;
		z++;
		}
		
		cout << z << endl;
	
}
