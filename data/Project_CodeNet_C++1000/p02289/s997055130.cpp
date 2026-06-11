#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
using namespace std;

int main()
{
	priority_queue<int> Q;
	string s;
	int num;
	while (cin >> s) {
		if (s == "end")break;
		scanf("%d", &num);
		if (s[0] == 'i')Q.push(num);
		if (s[0] == 'e') {
			printf("%d\n", Q.top());
			Q.pop();
		}
	}
	return 0;
}