#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
int main() {
	vector<pair<int,string>> x(1000);
	string a;
	int j=1,s=0,m=0;
	while(cin >> a) {
		for (int i = 0; i <j ; i++) {
			if (x[i].second == a) {
				x[i].first++;
				break;
			}
			if (i == j - 1) {
				x[i].second = a;
				x[i].first = 1;
				j++;
				break;
			}
		}
	}
	sort(x.begin(), x.end(), greater<pair<int, string>>());
	for (int i = 0; i < j; i++) {
		if (x[i].second.size() > s) {
			s = x[i].second.size();
		}
	}
	for (int i = 0; i < j; i++) {
		if (x[i].first > m) {
			m = x[i].first;
		}
	}
	for (int i = 0; i < j; i++) {
		if (x[i].first == m) {
			cout << x[i].second << ' ';
		}
	}
	for (int i = 0; i < j; i++) {
		if (x[i].second.size() == s) {
			cout << x[i].second << endl;
		}
	}
	return 0;
}