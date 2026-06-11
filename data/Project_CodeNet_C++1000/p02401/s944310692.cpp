#include<iostream>
#include<stdio.h>
using namespace std;
int main() {
	int a, b;
	int re;
	char calc;
	while(cin >> a >> calc >> b && calc != '?') {
	    if (calc == '+') {
			re = a + b;
	    } else if (calc == '-') {
			re = a - b;
	    } else if (calc == '*') {
			re = a * b;
	    } else if (calc == '/') {
			re = a / b;
	    }
	    //cout << re << endl;
	        printf("%d\n", re);
        }
}