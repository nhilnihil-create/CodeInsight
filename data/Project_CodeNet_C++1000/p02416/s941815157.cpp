#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
	string str;
	int i;
	int sum;
	char numstr[10];
	while(1) {
		getline(cin, str);

		if(str == "0") break;
		sum = 0;
		for(i = 0; i < str.size(); i++) {
			sprintf(numstr, "%c", str[i]);
			sum += atoi(numstr);
		}
		cout << sum << endl;
	}
	return 0;
}