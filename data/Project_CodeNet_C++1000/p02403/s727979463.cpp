#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;
#define A

#ifdef A
int main(void)
{
	int W, H;
	vector<pair<int, int> > arr(0);

	while (true)
	{
		cin >> H >> W;

		if (W == 0 || H == 0)
			break;
		arr.push_back(pair<int, int>(H, W));

	}

	for (auto a : arr) {
		for (size_t i = 0; i < a.first; i++)
		{
			for (size_t i = 0; i < a.second; i++)
			{
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}



	return 0;
}


#endif // A

#ifdef B
int main(void)
{
	return 0;
}
#endif // B


#ifdef C
int main(void)
{
	return 0;
}
#endif // C

#ifdef D
int main(void)
{

	return 0;
}

#endif // D