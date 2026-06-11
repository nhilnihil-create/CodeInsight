#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;


void func()
{
	int N, K;
	cin >> N >>K;

	vector<int>sunuke(N, 0);
	for (int i = 0; i < K; ++i)
	{
		int di;
		cin >> di;
		for (int j = 0; j < di; ++j)
		{
			int index;
			cin >> index;
			sunuke[index - 1]++;
		}
	}
	cout << count(sunuke.begin(), sunuke.end(), 0)  << endl;
}

int main() {

//	while (1)
		func();
	return 0;
}
