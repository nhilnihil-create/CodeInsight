#include <iostream>
#include <string>
#include <queue>
using namespace std;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_B&lang=jp

int main() {
	int n, q;
	cin >> n >> q;
	queue<string> names;
	queue<int> times;
	int current = 0;
	for (int i = 0; i < n; i++) {
		string str;
		int time;
		cin >> str >> time;
		names.push(str);
		times.push(time);
	}
	while (names.size() > 0) {
		string name = names.front(); names.pop();
		int time = times.front(); times.pop();
		if (time > q) {
			time -= q;
			names.push(name);
			times.push(time);
			current += q;
		} else {
			current += time;
			cout << name << " " << current << endl;
		}
	}
	
	return 0;
}