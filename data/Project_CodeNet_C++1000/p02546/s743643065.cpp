#include <iostream>
#include <string>

using namespace std;

int main() {
	string name,last;
	
	int n = 0;

	cin >> name;
	n = name.length();
	//末尾の検索
	last = name.substr(n-1);
	

	if (last == "s") {
		name = name + "es";
	}
	else
		name = name + 's';

	cout << name;

}