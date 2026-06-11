#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define cDefNum (10)

int main()
{
	size_t N,M;
	cin >> N >> M;

	int S[3] = { cDefNum,cDefNum,cDefNum };

	for (size_t i = 0; i < M; ++i)
	{
		int si, ci;
		cin >> si>> ci;
		if (S[si - 1] != cDefNum && S[si - 1] != ci)
		{
			cout << -1 << endl;
			return 0;
		}
		S[si - 1] = ci;
	}

	if ( S[0] == 0 && N > 1)
	{
		cout << -1 << endl;
		return 0;
	}

	if (S[0] == cDefNum && N == 1)//N==1
	{
		cout << 0 << endl;
		return 0;
	}
	
	if (S[0] == cDefNum)
	{
		S[0] = 1;
	}
	for (size_t i = 0; i < N; ++i)
	{
		cout << (S[i] == cDefNum ? 0 : S[i]);
	}
	cout << endl;

	return 0;
}