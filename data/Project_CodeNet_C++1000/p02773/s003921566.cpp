#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace  std;


int main() {
	int N;
	cin >> N;
	vector<string> str(N+1);
	vector<int> num(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> str.at(i);
	}
	sort(str.begin(), str.end()-1);
	int next = 0;
	for (int i = 0; i < N; i++) {
		num.at(i) = next;
		if (str.at(i) == str.at(i + 1)) { 
			next++; 
		}
		else {
			next = 0;
		}
	}
	int max_val = *max_element(num.begin(), num.end());
	for (int i = 0; i < N; i++) {

		if (num.at(i) == max_val)cout << str.at(i) << endl;
	}
	return 0;
}