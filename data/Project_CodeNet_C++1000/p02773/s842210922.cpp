#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	map<string, int> count;
	string input;

	while (cin >> input) { ++count[input]; }

	auto max_count{
		max_element(count.begin(), count.end(),
			[](const pair<string, int>& a, const pair<string, int>& b)
			{
				return a.second < b.second;
			}
		)->second
	};

	for (const auto& str_count : count)
	{
		if (str_count.second == max_count)
		{
			cout << str_count.first << '\n';
		}
	}
}