#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	int stack[103]={0};
	int pointer=0;
	bool flag=true;

	getline(cin,s);
	while (s!=".")
	{
		for (int i=0;i<s.length();++i)
		{
			if (s[i]=='(') stack[pointer++] = 1;
			if (s[i]=='[') stack[pointer++] = 2;
			if ((s[i]==')')&&(stack[--pointer]!=1)) {flag=false; break;}
			if ((s[i]==']')&&(stack[--pointer]!=2)) {flag=false; break;}
		}

		if (flag&&pointer==0) cout<<"yes"<<endl;
		else cout<<"no"<<endl;

		flag = true;
		pointer = 0;
		getline(cin,s);
	}
}