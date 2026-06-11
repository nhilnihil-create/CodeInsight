#include <bits/stdc++.h>
#include<cstring>
using namespace std;

int main() {
	// your code goes here
	char s[101];
	cin.getline(s,101);
/*	char s1[100];
	cin.getline(s, 100); 
	strcpy(s1,s);
	reverse(s1, s1 + strlen(s1));*/
	int count = 0;
	int n = strlen(s);
	for(int i = 0; i<n; i++)
	{
		if(s[i]!=s[n-i-1])
		{
			count++;
		}
	}
	cout<<count/2;
	return 0;
}