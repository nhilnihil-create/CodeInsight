#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	char c;
	int a,li,ls;
	string accion;
    getline(cin,s);
    cin>>a;
    while(a--)
    {
		cin>>accion;
		if(accion=="replace")
		{
			cin>>li>>ls;
			for(int i=li;i<=ls;i++)
			cin>>s[i];
		}else if(accion=="reverse")
		{	cin>>li>>ls;
			for(int i=0;i<=(ls-li)/2;i++)
		{	c=s[li+i];
			s[li+i]=s[ls-i];
			s[ls-i]=c;
	    }
	   }
		else
	    {	cin>>li>>ls;
		  	for(int i=li;i<=ls;i++)
		  	cout<<s[i];
		  	cout<<endl;
		}
	}
	
	return 0;
}

