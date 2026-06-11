#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;
map<string, int> mp;
string name;
int s[110];
int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> name >> s[i];
		mp[name] = i;
	}
	cin >> name;
	int sum = 0;
	for (int i = mp[name] + 1; i <= n; ++i) sum += s[i];
	printf("%d\n", sum);
	return 0;
}