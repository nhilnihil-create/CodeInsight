#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <math.h>

using namespace std;
void func()
{
	string S;
	string head, tail;
	int T, F, Q;
	bool isReverse=false;
	char c;
	cin >> S;
	cin >> Q;
	for (int i = 0; i < Q; ++i)
	{
		cin >> T;
		if (T==1)
		{
			isReverse = !isReverse;
		}
		else
		{
			cin >> F >> c;
			if (F == 1)
			{
				if (isReverse)
				{
					tail = tail + c;
				}
				else
				{
					head = c + head;
				}
			}
			else
			{
				if (isReverse)
				{
					head = c + head;
				}
				else
				{
					tail = tail + c;
				}
			}
		}
	}
	S = head + S + tail;
	if (isReverse)
	{
		reverse(S.begin(), S.end());
	}
	cout << S <<endl;
}

int main() {
//	while(1)
	func();
	return 0;
}
