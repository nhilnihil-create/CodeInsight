#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int sum = 0;
	for (char &c : s){
		sum += c - '0';
	}
	if (sum % 9)cout << "No";
	else cout << "Yes";

	//system("pause");
	return 0;
}
