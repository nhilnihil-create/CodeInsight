#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
	int pos;
	int num;
}a[100005];
bool cmp(node x, node y)
{
	return x.num < y.num;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].num;
		a[i].pos = i;
	}
	sort (a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)cout << a[i].pos << " ";
	return 0;
} 