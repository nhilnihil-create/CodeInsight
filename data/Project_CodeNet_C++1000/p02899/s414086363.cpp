#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n; cin >> n;
	vector<int> a(n);
	vector<int> att(n);
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
		att.at(a.at(i) - 1) = i + 1;
	}
	for (int i = 0; i < n; i++) cout << att.at(i) << " ";
	cout << endl;
}