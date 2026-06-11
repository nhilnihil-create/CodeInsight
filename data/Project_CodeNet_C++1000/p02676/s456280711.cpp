#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
	int k;
	string s;
	cin >> k >> s;
	cout << (s.size() <= k ? s : s.substr(0,k) + "...") << endl;
}

