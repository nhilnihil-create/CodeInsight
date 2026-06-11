#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
int main() {
	int n, mini = 1000000000;
	int cnt = 1;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	mini = a.at(0);
	for (int i = 1; i < n; i++) {
		if (mini > a.at(i)) {
			cnt++;
			mini = a.at(i);
		}
	}
	cout << cnt << endl;
	return 0;
	
}