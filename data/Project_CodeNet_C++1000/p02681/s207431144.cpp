#include <iostream>
#include <algorithm>
#include<set>
#include<math.h>
#include<string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


int main() {
	int n=0;
	string s,str;
	cin>>s>>str;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==str[i])
		{
			n+=1;
		}
	}
	if (n==s.size() && str.size()==(s.size()+1))
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0;
}