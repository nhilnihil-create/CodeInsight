#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

#include <queue>

using namespace std;


typedef long long LL;;


typedef pair <int, int> pr;


const int N = 2e5 + 10;


int a[N], b[N];
int n;

priority_queue <pr> q;

int main()
{
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	
	for (int i = 1; i <= n; i++) q.push(make_pair(b[i], i));
	
	LL Ans = 0;
	
	while (!q.empty())
	{
		pr now = q.top(); q.pop();
		int val = now.first, id = now.second;
		if (val == a[id]) continue;
		if (val < a[id]) return 0 & puts("-1");
		int w = val - a[id]; 
		int num = b[id < n ? id + 1 : 1] + b[id > 1 ? id - 1 : n];
		if (num > w) return 0 & puts("-1");
		Ans += w / num;
		b[id] -= (w / num) * num;
		q.push(make_pair(b[id], id));
	}
	
	printf("%lld\n", Ans);
	
	return 0;
}