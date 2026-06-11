#include<iostream>
#include<string>
using namespace std;
int main()
{
	string  dog;
	string pig;
	getline(cin, dog);
	getline(cin, pig);
	string cat = pig.substr(0, pig.size() - 1);
	//cout << cat;
	if (dog == cat)
		cout << "Yes";
	else
		cout << "No";

    return 0;
}