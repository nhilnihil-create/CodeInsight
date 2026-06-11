#include <iostream>
 
using namespace std;
 
int main(){
	int a,b;
	int k;
	cin >> a >> b;
	if(a%2 != b%2){
		cout << "IMPOSSIBLE" << "\n";
	}else{
		cout << (a+b)/2;
	}
}
 
 