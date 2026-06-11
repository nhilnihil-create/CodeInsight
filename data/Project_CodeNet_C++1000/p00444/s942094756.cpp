//
//  main.cpp

#include <iostream>
using namespace std;


int main(){	
	int x;
	while(1){
		cin >> x;
		if(x == 0)break;
		x = 1000 - x;
		int answer = 0;
		answer += x / 500;
		x %= 500;
		answer += x / 100;
		x %= 100;
		answer += x / 50;
		x %= 50;
		answer += x / 10;
		x %= 10;
		answer += x / 5;
		x %= 5;
		answer += x;
		cout << answer << endl;
	}
	return 0;
}