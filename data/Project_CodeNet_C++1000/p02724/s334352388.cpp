#include<iostream>
#include<string>
using namespace std;
int main()
{
	//string dog;
	//getline(cin, dog);
	//if (dog[2] == dog[3] && dog[4] == dog[5])
	//	cout << "Yes";
	//else
	//	cout << "No";
	long long dog;
	cin >> dog;
	int ans = 0;
	ans += dog / 500 * 1000;
	dog -= dog / 500 * 500;
	ans += dog / 5 * 5;
	cout << ans;
    return 0;
}

