#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	string S;
	cin >> N >> S;

	int count = 1;

	for (int i = 0; i < (int)S.size() - 1; i++) {
		if (S[i] != S[i + 1])
			count++;
	}

	cout << count << endl;

	return 0;
}