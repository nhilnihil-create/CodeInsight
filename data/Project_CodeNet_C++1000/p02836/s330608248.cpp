#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	string str;
	cin>>str;
	int mid = str.length()/2;
	int len = str.length();
	int counter{};
	for(int i=0;i<mid;i++)
		if(str[i] != str[len - 1 - i])
			counter++;
	cout<<counter;
	return 0;
}