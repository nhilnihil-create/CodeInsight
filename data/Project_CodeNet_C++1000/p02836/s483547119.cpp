#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s1;
	int x = 0, k = 0, i;

	cin >> s1;
	x = s1.size();

	for (i = 0; i < x; i++) {
		if (s1[i] != s1[x - 1 - i]) k++;
	}
	cout << k/2 << endl;
	return 0;
}