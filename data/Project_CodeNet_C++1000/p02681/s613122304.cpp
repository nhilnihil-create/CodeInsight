# include <iostream>

using namespace std;

int main()
{
	string S, T;

	cin >> S;
	cin >> T;

	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] != T[i])
			goto no;
	}

	cout << "Yes";
	goto end;

no:
	cout << "No";
end:

	return 0;
}