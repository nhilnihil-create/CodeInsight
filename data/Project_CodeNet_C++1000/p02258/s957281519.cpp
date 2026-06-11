#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	
	vector<int> vr;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		vr.push_back(t);
	}

	int profit = vr[1] - vr[0];
	for (int i = 0; i < vr.size() -1; ++i)
	{
		for (int j = i + 1; j < vr.size(); ++j)
		{
			profit = max(profit, vr[j] - vr[i]);
			if (vr[j] - vr[i] < 0)break;
		}
	}
	cout << profit << endl;

	return 0;
}