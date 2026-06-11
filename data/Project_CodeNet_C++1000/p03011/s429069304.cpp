#include <iostream>
using namespace std;

int main() {
	int AB; int BC; int CA;
	cin>> AB>>BC>>CA;
	int first= AB+BC;
	int second= BC+CA;
	int third= AB+CA;
	if(first<=second && first<=third){
		cout<<first;
	}
	else if (second<=first && second<=third){
		cout<<second;
	}
	else{
		cout<<third;
	}
	return 0;
}