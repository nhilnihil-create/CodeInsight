#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<string> shit = {"pon","pon","hon","bon","hon","hon","pon","hon","pon","hon"};
	cout << shit[s.back()-'0'] << endl;
}