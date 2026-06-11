#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	typedef pair<int, int> int_pair;
	vector<int_pair> a;

	while (true)
	{
		int H, W;
		cin >> H >> W;

		a.push_back(int_pair(H, W));

		if (H == 0 && W == 0)
			break;
	}

	for (int i = 0; a[i].first != 0 && a[i].second != 0; ++i)
	{
		for (int h = 0; h < a[i].first; ++h) {

			if (h == 0 || h == a[i].first - 1)
				for (int w = 0; w < a[i].second; ++w)
					cout << '#';
			else
				for (int w = 0; w < a[i].second; ++w)
					if (w == 0 || w == a[i].second - 1)
						cout << "#";
					else
						cout << ".";

			cout << endl;
		}

		cout << endl;
	}

	return 0;
}