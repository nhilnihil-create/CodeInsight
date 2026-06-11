#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back


int main() {
	vector<int> v;
	for (int i = 1; i < 10; i++){
		for (int j = i; j < 10; j++){
			v.push_back(i * j);
		}
	}
	int n;
	cin >> n;
	if (count(v.begin(), v.end(), n) == 0){
		cout << "No";
	} else {
		cout << "Yes";
	}
}
