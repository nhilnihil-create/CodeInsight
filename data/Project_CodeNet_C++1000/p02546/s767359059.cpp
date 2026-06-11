#include <iostream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
	string s;
	cin>>s;
	if(s[s.size()-1]=='s')
	{
		for(int i=0;i<s.size();i++)
		{
			cout<<s[i];
		}
		cout<<"es";
	}else{
		for(int i=0;i<s.size();i++)
		{
			cout<<s[i];
		}
		cout<<"s";
	}
	return 0;
}