#include <iostream>
#include <string>    
#include <fstream>   

using namespace std;

int main() {

	string str1, str2;
	cin >> str1;
	cin >> str2;
	
	int len1 = str1.length();
	int len2 = str2.length();

	int count = 0;
	int result = len1;

	for (int top = 0; top <= len1 - len2; top++) {
		count = 0;
		int idx = 0;
		for (int now = top; now < top + len2; now++) {
			//cout << now;
			if (str1[now] != str2[idx]) {
				count++;
			}
			idx++;
		}
		//cout << endl;
		if (count < result) {
			result = count;
		}
	}

	cout << result;

	return 0;
}