#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int arr[101] = {0};

int main()
{
	string n, m, l;
	cin >> n;
	for(int i=n.length()-1; i>=0; i--)
	{
		m += n[i];
	}
	if(n != m)
	{
		cout << "No";
		return 0;
	}
	for(int i=n.length()/2+1; i<n.length(); i++)
	{
		l += n[i];
	}
	for(int i=0; i<l.length(); i++)
	{
		if(n[i] != l[i])
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}

