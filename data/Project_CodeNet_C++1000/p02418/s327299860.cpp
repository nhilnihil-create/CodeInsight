#include <iostream>
#include <string.h>
using namespace std;

int main(void){
	char str[200], ans[100];

	cin >> str;
	cin >> ans;

	//????????°????????\
	int ansLen = strlen(ans), strLen = strlen(str);
	for (int i = 0; i < ansLen; i++){
		str[strLen + i] = str[i];
		if (i == ansLen - 1){
			str[strLen + i + 1] = '\0';
		}
	}

	//??¢?´¢
	strLen += ansLen;
	for (int i = 0, j=0; i < strLen; i++){
		j = 0;
		for (int k = i; k < strLen; k++){
			//??§???
			if (str[k] == ans[j]){
				j++;
			}
			else {
				j = (str[k] == ans[0]) ? 1 : 0;
			}

			//????????????
			if (ans[j] == '\0'){
				cout << "Yes\n";
				return 0;
			}
			else if (str[i + 1] == '\0'){
				break;
			}
		}

		//????????????
		if (str[i+1] == '\0'){
			cout << "No\n";
			break;
		}
	}

	return 0;
}