#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Stack {
private:
	long idx;
	long stk[100];

public:
	Stack() {
		idx = -1;
	}
	void push(long l) {
		stk[++idx] = l;
	}
	long pop() {
		return stk[idx--];
	}
	bool size() {
		return idx + 1;
	}
};

int main(){
	Stack stk;
	char token[10];
	while (scanf("%s", token) != EOF) {
		if (*token == '+') {
			long b = stk.pop();
			long a = stk.pop();
			stk.push(a + b);
		} else if (*token == '-') {
			long b = stk.pop();
			long a = stk.pop();
			stk.push(a - b);
		} else if (*token == '*') {
			long b = stk.pop();
			long a = stk.pop();
			stk.push(a * b);
		} else {
			stk.push(atoi(token));
		}
	}

	while (stk.size()) {
		cout << stk.pop() << endl;
	}

	return 0;
}