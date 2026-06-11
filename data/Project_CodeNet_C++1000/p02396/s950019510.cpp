#include<iostream>
#include<queue>
using namespace std;

int main() {
	queue<int> q;
	int tmp;
	while (1) {
		cin >> tmp;
		if (!tmp) break;
		q.push(tmp);
	}
	int n = q.size();
	for (int i = 1; i <= n; i++ ){
		cout << "Case " << i << ": " << q.front() << endl;
		q.pop();
	}
	return 0;
}