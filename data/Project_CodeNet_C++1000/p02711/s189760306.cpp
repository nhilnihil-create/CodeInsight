#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<set>
#include<string>
#include<bitset>
using namespace std;


int main() {
	int N;
	cin >> N;

	if (((N / 100) % 10) == 7 || ((N / 10) % 10) == 7 || ((N / 1) % 10) == 7) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
	return 0;

}