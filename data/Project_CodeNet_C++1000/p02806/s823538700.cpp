#include <bits/stdc++.h>
using namespace std;

int n;
int num[55], ans;

map<string, int> id;

string s;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s >> num[i], id[s] = i;
	cin >> s;
	for(int i = id[s] + 1; i <= n; i++) ans += num[i];
	printf("%d", ans);
	return 0;
}