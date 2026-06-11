#include <iostream>
#include <string>
using namespace std;

string s, t[5] = {"hi", "hihi", "hihihi", "hihihihi", "hihihihihi"};
bool f = 0;

int main()
{
	cin >> s;

	for (int i = 0; i < 5; i++)
		if (t[i] == s)
			f = 1;

	if(f)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
