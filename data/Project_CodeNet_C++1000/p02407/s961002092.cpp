#include<iostream>
using namespace std;
int main() {
	int datan, data[1000];
	cin >> datan;
	for (int i = 0; i < datan; i++)
		cin >> data[i];
	for (int i = datan-1; i >0; i--)
		cout << data[i] << " ";
	cout << data[0] << endl;
	return 0;
}