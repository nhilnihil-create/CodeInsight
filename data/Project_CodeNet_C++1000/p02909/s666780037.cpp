#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;
	cin >> name;
	if (name == "Sunny"){
		cout << "Cloudy" << endl;
	}
	else if (name == "Cloudy"){
		cout << "Rainy" << endl;
	}
	else{
		cout << "Sunny" << endl;
	}
}