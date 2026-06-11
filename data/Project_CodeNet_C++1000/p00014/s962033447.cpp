#include <iostream>
using namespace std;

int main(){
	while(true){
	
	int d;
	cin >> d;
	if(cin.eof())
		break;
	int area = 0;
	for (int i = 0; i <600;i+=d){
		area += d * i * i;
	}
	cout << area << endl;
	area = 0;
	}
	return 0;
}