#include <iostream>
#include <string>

using namespace std;

class IntStack {
private:
	const static int MAX = 300;
	int s[MAX];
	int top;

public:
	IntStack();
	bool isEmpty();
	bool isFull();
	void push(int);
	int pop();
};

int main(void) {
	string str;
	int a, b;
	IntStack s;

	while (cin >> str) {
		if (str == "+"){
			a = s.pop();
			b = s.pop();
			s.push(b + a);
		}
		else if (str == "-") {
			a = s.pop();
			b = s.pop();
			s.push(b - a);
		}
		else if (str == "*") {
			a = s.pop();
			b = s.pop();
			s.push(b * a);
		}
		else {
			s.push(stoi(str));
		}
	}

	cout << s.pop() << "\n";

	cin >> a;
	return 0;
}


IntStack::IntStack() {
	top = 0;
}

bool IntStack::isEmpty() {
	return top == 0;
}

bool IntStack::isFull() {
	return top >= MAX - 1;
}

void IntStack::push(int n) {
	if (isFull()) {
		cout << "error: over flow\n";
		return;
	}
	top++;
	s[top] = n;
}

int IntStack::pop() {
	if (isEmpty()) {
		cout << "error: under flow\n";
		return '\0';
	}
	top--;
	return s[top + 1];
}