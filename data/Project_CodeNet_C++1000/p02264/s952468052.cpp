#include <string>
#include <stack>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;


#if 0
queue<pair<string, int>>はダメです。queue<pair<string, int> >の中の’’は必要です。
#endif
pair<string, int> process;
queue<pair<string, int> > Q;
int main()
{
	int j = 0, times = 0;
    int n, q;
	cin >> n >> q;
	for (int i = 0; i<n; i++)
	{
		cin >> process.first >> process.second;
		Q.push(process);
	}
	while (!Q.empty()) {
		process = Q.front(); Q.pop();
		if (process.second > q) {
			process.second -= q;
			times += q;
			Q.push(process);
		}
		else {
			times += process.second;
			cout << process.first << " " << times << endl;
		}
	}
	return 0;
}
