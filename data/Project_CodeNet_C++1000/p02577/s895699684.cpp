#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main() {
	string s;
	cin >> s;
	int sum = 0;
	for (char c : s) {
		sum += c - '0';
	}
	if (sum % 9 == 0) {
		cout<<"Yes"<<endl;
	}
	else {
		cout << "No" << endl;
	}
	
	return 0;
}