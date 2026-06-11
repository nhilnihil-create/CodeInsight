#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define the_flash ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define input_output freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)

using namespace std;

int main()
{
	//input_output;
	the_flash;
	int t;
	cin >> t;
	map<string, int> freq;
	int max = 0;

	for (int i = 0; i < t; i++)
	{
		string s;
		cin >> s;
		freq[s]++;

		if (freq[s] > max)
			max = freq[s];
	}

	for (auto i = freq.begin(); i != freq.end(); i++)
	{
		if (i -> second == max)
			cout << i -> first  << endl;
	}
	return 0;
}