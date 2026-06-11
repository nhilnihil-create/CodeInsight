#include <iostream>
#include <set>
#include <vector>

#include <algorithm>


using namespace std;


int main() {
	int N;

	vector<int> va;
	vector<int> vb;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;

		va.push_back(a);
		vb.push_back(b);
		
	}


	if (N % 2 == 1) {//奇数

		sort(va.begin(), va.end());
		int min = va[(N + 1) / 2 -1];


		sort(vb.begin(), vb.end());
		int max = vb[(N + 1) / 2 -1];

		
		cout << max - min + 1;

	}
	else
	{

		sort(va.begin(), va.end());
		int min = va[(N) / 2 - 1];
		int min1 = va[(N) / 2];


		sort(vb.begin(), vb.end());
		int max = vb[(N) / 2 - 1];
		int max1 = vb[(N) / 2];

		int s = -1;
		if ((min + min1) % 2 == 1)s--;
		if ((max + max1) % 2 == 1)s++;

		min = (min + min1) / 2;
		max = (max + max1) / 2;

		cout << (max - min + 1)*2 +s;

	}


	return 0;

}