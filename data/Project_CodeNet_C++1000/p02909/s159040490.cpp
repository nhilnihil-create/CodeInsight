#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<string, string> next;
	next["Sunny"] = "Cloudy";
	next["Cloudy"] = "Rainy";
	next["Rainy"] = "Sunny";
	string ac;
	cin >> ac;
	cout << next[ac];
	return 0;
}