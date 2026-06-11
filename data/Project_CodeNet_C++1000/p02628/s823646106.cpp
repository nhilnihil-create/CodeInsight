#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int size1, size2;
	cin >> size1 >> size2;
	vector <int> vect(size1);
	for (int i = 0; i < size1; i++) {
		cin >> vect[i];
	}
	sort(vect.begin(), vect.end());
	int sum = 0;
	for (int i = 0; i < size2; i++) {
		sum += vect[i];
	}
	cout << sum;
	return 0;
}