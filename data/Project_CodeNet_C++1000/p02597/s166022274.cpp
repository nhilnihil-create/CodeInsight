#include<iostream>
#include<string>

using namespace std;

int main()
{
	int N;
	string s;

	cin >> N;

	cin >> s;

	int cnt = 0;
	for (int i = 0; i < N; i++)
		if (s[i] == 'R')
			cnt++;

	int ans = 0;
	for (int i = 0; i < cnt; i++)
		if (s[i] == 'W')
			ans++;

	cout << ans;
}