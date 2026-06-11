#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define STRMAX 1005
#define ORDREMAX 20


int main(void)
{
	char	str[STRMAX];
	int		num, i, j, k, under, over;
	char	substr[STRMAX];
	char	order[ORDREMAX];
	char	tmp;

	cin >> str;
	cin >> num;

	for (i=0; i<num; i++) {
		cin >> order >> under >> over;

		if (strcmp(order, "print") == 0) {
			for (j=under; j<=over; j++) {
				cout << str[j];
			}
			cout << endl;
		}
		else if (strcmp(order, "replace") == 0) {
			cin >> substr;
			k = 0;
			for (j=under; j<=over; j++) {
				str[j] = substr[k];
				k++;
			}
		}
		else if (strcmp(order, "reverse") == 0) {
			j = under;
			k = over;
			while (1) {
				if (under >= over) {
					break;
				}
				else {
					tmp = str[under];
					str[under] = str[over];
					str[over] = tmp;
					under++;
					over--;
				}
			}
		}
	}


	return 0;
}
