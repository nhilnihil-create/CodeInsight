#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define P pair<string,int>
using namespace std;

int main() {
	priority_queue<int>a;
	string b;
	while (cin >> b, b[2]!= 'd') {
		if (b[0] == 'i') {
			int c;
			scanf("%d", &c);
			a.push(c);
		}
		else {
			int d = a.top();
			a.pop();
			printf("%d\n", d);
		}
	}
}