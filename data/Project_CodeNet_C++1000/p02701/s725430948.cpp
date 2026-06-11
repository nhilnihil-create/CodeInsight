#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	int num;
	std::cin >> num;
	int count = 0;
	map<string,int> keihinn;

	for (int i = 0;i < num;i++) {
		string tmp;
		std::cin >> tmp;
		if (keihinn.find(tmp) != keihinn.end())keihinn[tmp] = 1;
		else keihinn[tmp]++;
	}
	cout << keihinn.size() << endl;

	return 0;
}