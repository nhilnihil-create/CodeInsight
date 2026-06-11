#include <iostream>

using namespace std;

int main()
{
	int n;
	string S;
	cin >> n;
	cin >> S;
	if (n%2 == 1){
		cout << "No" << endl;
		return 0;
	}
	int flag = 0;
	int haf = n /2;
	for (int i = 0; i<haf; i++)
	{
		if(S[i] != S[haf+i])
		{
			flag = 1;	
		}
	}
	
	if(flag == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}