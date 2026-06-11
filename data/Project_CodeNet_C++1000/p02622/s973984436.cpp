#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{	ios_base::sync_with_stdio(false);    cin.tie(NULL);
	string s1,s2;
	cin>>s1 >> s2;
	int count =0 ;
	for(int i=0; i<s1.length(); i++)
		if(s1[i] != s2[i])
			count++;
	cout<<count<<"\n";
	return 0;

}