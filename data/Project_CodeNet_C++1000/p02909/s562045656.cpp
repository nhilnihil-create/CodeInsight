#include <iostream>

using namespace std;

int main(){
	char* weather = (char*)calloc(10, sizeof(char));
	cin >> weather;

	if(*weather == 'S') cout << "Cloudy";
	else if(*weather == 'C') cout << "Rainy";
	else if(*weather == 'R') cout << "Sunny";
	cout << endl;
	return 0;
	
}