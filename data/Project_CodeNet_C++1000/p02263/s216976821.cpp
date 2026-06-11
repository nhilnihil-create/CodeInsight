#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Siki {

	int stack[100];		//????????????
	int num;			//????´???°

	

public:
	Siki() {
		num = 0;
	}

	void push( int val ) {
		if (num >= 100) {
			cout << "overflow" << endl;
			return;
		}
		stack[num] = val;
		num++;
	}

	int pop() {
		if (num == 0) {
			cout << "underflow" << endl;
			return -1;
		}
		num--;
		return stack[num];
	}

	int getTop() { return stack[num-1]; }
	int getValue(int n) { return stack[n]; }

};

int main() {

	Siki s;

	//??°???????????§7??? 100?????\??????700????????\???
	//?????????99?????\?????????99????????\???
	//????¨?800????????§??????

	char input[800];
	for (int i = 0; i < 800; i++) {
		input[i] = '\0';
	}

	gets(input);

	int kazu = 0;
	char in[100];

	while (sscanf(input, "%s", in, sizeof(in) ) == 1) {

		if(in[0] == '+'){
			int a = s.pop();
			int b = s.pop();
			s.push(b + a);
		}
		else if (in[0] == '-') {
			int a = s.pop();
			int b = s.pop();
			s.push(b - a);
		}
		else if (in[0] == '*') {
			int a = s.pop();
			int b = s.pop();
			s.push(b * a);
		}
		else if (in[0] == '/') {
			int a = s.pop();
			int b = s.pop();
			s.push(b / a);
		}
		else {
			
			s.push( atoi(in) );
			
		}
		int l = strlen(in) + 1;
		for (int i = 0; i < 800-l; i++) {
			input[i] = input[i + l];
		}
		
	}
	cout << s.pop() << endl;
	
	return 0;


}