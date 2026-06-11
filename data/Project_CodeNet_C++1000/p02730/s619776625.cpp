#include<iostream>
#include <string>
using namespace std;
int main()
{
	int bResult = 0;
	string strInput;
	cin >> strInput;

	int strLength = strInput.length();
	int halfLength = strLength / 2;

	for (int i = 0; i < halfLength - 1; i++) {
		if (strInput[i] == strInput[strLength - i - 1]) {
			//何もしない
		}
		else {
			//回文じゃない
			bResult = 1;
			break;
		}
	}
	//普通の回文だったら前半をサーチする
	if (bResult == 0) {
		for (int i = 0; i < halfLength - 1; i++) {
			if (strInput[i] == strInput[halfLength - i - 1]) {
				//何もしない
			}
			else {
				//回文じゃない
				bResult = 1;
				break;
			}
		}
	}
	//普通の回文だったら後半もサーチする
	if (bResult == 0) {
		for (int i = 0; i < halfLength - 1; i++) {
			if (strInput[halfLength + 1 + i] == strInput[strLength - i - 1]) {
				//何もしない
			}
			else {
				bResult = 1;
				break;
			}
		}
	}

	if (bResult == 1) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}

	return 0;
}