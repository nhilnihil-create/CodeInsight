# include <iostream>
# include <math.h>

using namespace std;

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	int K;
	string S;

	cin >> K;
	cin >> S;

	for (int i = 0; i < min(K,S.length()); i++)
	{
		cout << S[i];
	}
	if(K<S.length())
		cout << "...";

    return 0;
}