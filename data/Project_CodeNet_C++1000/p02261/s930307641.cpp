#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <string>

#define INT_MAX 2147483647
#define INT_MIN -2147483647
using namespace std;

void bubble_sort(vector<pair<char, int> > &data)
{
	for (int i = 1; i < data.size(); ++i)
	{
		for (int j = data.size() - 1; j>=i; --j)
		{
			if (data[j].second < data[j - 1].second)
				swap(data[j], data[j - 1]);
		}
	}
}

void select_sort(vector<pair<char, int> > &data)
{
	for (int i = 0; i < data.size(); ++i)
	{
		int idx = i;
		for (int j = i + 1; j < data.size(); ++j)
		{
			if (data[j].second < data[idx].second)
			{
				idx = j;
			}
		}
		swap(data[i], data[idx]);
	}
}

void print(vector<pair<char, int> > &data)
{
	for (int i = 0; i < data.size() - 1; ++i)
		cout << data[i].first << data[i].second << " ";

	cout << data.back().first << data.back().second << endl;
}

bool equal(vector<pair<char, int> > &data1, vector<pair<char, int> > &data2)
{
	for (int i = 0; i < data1.size() -1; ++i)
	{
		if (data1[i] != data2[i])
			return false;
	}
	return true;
}

int main()
{
	vector<pair<char, int> > data1, data2;

	int num = 0;
	cin >> num;

	string s;
	while (cin >> s)
		data1.push_back(make_pair(s[0], s[1] - '0'));
	data2.assign(data1.begin(), data1.end());

	bubble_sort(data1);
	select_sort(data2);

	print(data1);
	cout << "Stable" << endl;
	print(data2);
	cout << (equal(data1, data2) ? "Stable" : "Not stable") << endl;

	return 0;
}