#include <string>
#include <vector>
#include <iostream>

using namespace std;

string put_nchar(int n, char c)
{
	string S(n, c);

	return S;
}

void print_frame(int H, int W, char c1, char c2)
{
	cout << put_nchar(W, c1) << endl;

	for(int i = 1; i < H - 1; i++)
	{
		cout << c1 << put_nchar(W - 2, c2) << c1 << endl;
	}

	cout << put_nchar(W, c1) << endl;
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
		print_frame(H[i], W[i], '#', '.');

		cout << endl;
	}

	return 0;
}