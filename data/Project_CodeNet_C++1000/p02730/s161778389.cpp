#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin>>str;
	int n=str.size();
	string s=str;
	reverse(s.begin(),s.end());
	if(str!=s) {cout<<"No"<<endl;return 0;}
	int first=(n-1)/2;
	string str2(str.begin(),str.begin()+first);
	string str3=str2;
	reverse(str3.begin(),str3.end());
	if(str3!=str2) {cout<<"No"<<endl;return 0;}
	int last=(n+3)/2;
	string str4(str.begin()+last-1,str.end());

	string str5=str4;
	reverse(str5.begin(),str5.end());
	if(str5!=str4) {cout<<"No"<<endl;return 0;}
	cout<<"Yes"<<endl;
	return 0;
}