#include<iostream>
using namespace std;

int main() {
	int Array[1000][2];
	int i;
	for (i = 0;; i++){
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		Array[i][0] = a;
		Array[i][1] = b;
	}
	for (int n = 0; n < i; n++)
	{
		for (int k = 0; k < Array[n][0]; k++) {
			for (int i = 0; i < Array[n][1]; i++)
			{
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}
}