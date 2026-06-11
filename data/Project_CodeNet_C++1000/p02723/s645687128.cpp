#include<iostream>
#include<string>
using namespace std;
int main()
{
	string dog;
	getline(cin, dog);
	if (dog[2] == dog[3] && dog[4] == dog[5])
		cout << "Yes";
	else
		cout << "No";
    return 0;
}

