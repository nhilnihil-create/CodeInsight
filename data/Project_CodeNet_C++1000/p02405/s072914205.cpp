#include <vector>
#include <iostream>

using namespace std;

void print_chessboard(int H, int W, char c1, char c2)
{
	for(int i = 0; i < H; i++)
	{
		for(int j = 0; j < W; j++)
		{
			switch((i + j) % 2)
			{
			case 0: cout << c1; break;
			case 1: cout << c2;
			}
		}

		cout << endl;
	}
}

int main()
{
	vector<int> W, H;

	while(true)
	{
		int H1, W1;

		cin >> H1 >> W1;

		if(H1 == 0 && W1 == 0) { break; }

		H.push_back(H1);
		W.push_back(W1);
	}

	for(vector<int>::size_type i = 0; i < H.size(); i++)
	{
		print_chessboard(H[i], W[i], '#', '.');

		cout << endl;
	}

	return 0;
}