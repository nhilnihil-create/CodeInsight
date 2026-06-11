#include <iostream>
#include <string>
using namespace std;

int main(){
	int a = 0;
	string n;
	cin >> n;
	for (int i = 0; i < 3; i++)
		if (n[i] == '7')
			a++;
	if (a > 0)
		cout << "Yes";
	else
		cout << "No";
}