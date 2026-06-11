#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int main() {
	int N;
	cin >> N;
	map<string, int> list;
	vector<int>time(N);
	string S;
	for (size_t i = 0; i < N; i++)
	{
		cin >> S;
		list[S] = i;
		cin >> time.at(i);
	}
	cin >> S;
	int ans = 0;
	for (size_t i = list.at(S)+1; i < N; i++)
	{
		ans += time.at(i);
	}
	cout << ans;
    
}