#include<iostream>
#include<string>
#include<queue>
using namespace std;

string S;
priority_queue<int> Q;

int main() {
	int b;
	while (true) {
		cin >> S;
		if (S[0] == 'i') {
			cin >> b;
			Q.push(b);
		}
		if (S[1] == 'x') {
			cout << Q.top() << endl;
			Q.pop();

		}
		if (S[2] == 'd') {
			break;
		}
	}
	return 0;
}