#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int stoi(string str) {
	int ret;
	ret = int(str[1])-48;
 	return ret;
}

int main() {
	int n, min, flg;
	string tmp;
	cin >> n;
	string *org = new string[n];
	string *a = new string[n];
	
	for (int i = 0; i < n; i++)
		cin >> org[i];
	for (int i = 0; i < n; i++)
		a[i] = org[i];
	for (int i = 0; i < n -1; i++)
		for(int j = n - 1; j > i; j--)
			if (stoi(a[j]) < stoi(a[j - 1])) {
				tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
	flg = 1;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = 0; k < n - 1; k++)
				for (int l = k + 1; l < n; l++)
					if ((stoi(org[i]) == stoi(org[j])) && (org[i] == a[l]) && (org[j] == a[k]))
						flg *= 0;

	for (int i = 0; i < n - 1; i++)
		cout << a[i] << ' ';
		cout << a[n - 1] << endl;
	if (flg)
		cout << "Stable" << endl;
	else
		cout << "Not stable" << endl;
	for (int i = 0; i < n; i++)
		a[i] = org[i];
	for (int i = 0; i < n -1; i++) {
		min = i;
		for (int j = i + 1; j < n ; j++) {
			if (stoi(a[j]) < stoi(a[min]))
				min = j;
		}
		if (min != i) {
			tmp = a[i];
			a[i] = a[min];
			a[min] = tmp;
		}
	}
	flg = 1;
	for (int i = 0; i < n -1; i++)
		for (int j = i + 1; j < n ; j++)
			for (int k = 0; k < n - 1; k++)
				for (int l = k + 1; l < n; l++)
					if ((stoi(org[i]) == stoi(org[j])) && (org[i] == a[l]) && (org[j] == a[k]))
						flg *= 0;
	for (int i = 0; i < n - 1; i++)
		cout << (a[i]) << ' ';
		cout << (a[n - 1]) << endl;
	if (flg)
		cout << "Stable" << endl;
	else
		cout << "Not stable" << endl;
	return 0;
}