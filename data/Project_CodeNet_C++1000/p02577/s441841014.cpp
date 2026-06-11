#include <bits/stdc++.h>
using namespace std;

int main() {
	string n;
	cin >> n;
	int nl = n.size(),cnt=0;
	for(int i =0;i<nl;i++)
	{
		cnt+=(int)n.at(i)-48;
		cnt%=9;
	}
	if(cnt>0)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
	}
	return 0;
}
