#include <iostream>
using namespace std;
int main(void){
	int a;
	cin >> a;
	string b = "No";
	
	for(int i = 1; i < 10; ++i){
	    if(a%i == 0 && a/i < 10){
	         b = "Yes";
	    }
	}
	
	cout << b << endl;
}