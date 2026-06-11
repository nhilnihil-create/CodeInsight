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
	int n, m;
	long long int ans = 0;
	cin >> n >> m;
	priority_queue<int> q;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		q.push(a);
	}

	for (int i = 0; i < m; i++) {
		int a = q.top();
		q.pop();
		a = a / 2;
		q.push(a);
			}
	while (q.size()) {
		ans += q.top();
		q.pop();
	}
	cout << ans << endl;
	return 0;
	
}