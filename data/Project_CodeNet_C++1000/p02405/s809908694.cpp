#include <bits/stdc++.h>

using namespace std;

int main()
{
	int H , W;
	while(cin >> H >> W , H || W)
	{
		for(size_t i = 0; i < H; i++)
		{
			for(size_t j = 0; j < W; j++)
			{
				cout << ( ( i + j ) % 2 ? '.' : '#' );
			}
			cout << endl;
		}
		cout << endl;
	}
}