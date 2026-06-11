#include <iostream>
#include <string>
using namespace std;

int stoi(string str) {
	int ret;
	ret = int(str[1])-48;
 	return ret;
}
string ynstable(int n, string *org, string *a) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = 0; k < n - 1; k++)
				for (int l = k + 1; l < n; l++)
					if ((stoi(org[i]) == stoi(org[j])) && (org[i] == a[l]) && (org[j] == a[k]))
						return "Not stable";
	return "Stable";
}
int main() {
	int n, min;
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
	for (int i = 0; i < n - 1; i++)
		cout << a[i] << ' ';
	cout << a[n - 1] << endl;
	cout << ynstable(n, org, a) << endl;
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
	for (int i = 0; i < n - 1; i++)
		cout << (a[i]) << ' ';
	cout << (a[n - 1]) << endl;
	cout << ynstable(n, org, a) << endl;

	return 0;
}