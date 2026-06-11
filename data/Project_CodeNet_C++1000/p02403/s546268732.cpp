#include <string>
#include <vector>
#include <iostream>

using namespace std;

string put_nchar(int n, char c)
{
	string S(n, c);

	return S;
}

void print_rectangle(int W, int H, char c)
{
	for(int i = 0; i < H; i++)
	{
		cout << put_nchar(W, c) << endl;
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
		print_rectangle(W[i], H[i], '#');

		cout << endl;
	}

	return 0;
}