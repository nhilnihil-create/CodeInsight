#include <iostream>
#include <string>
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main() {
    string s="abcdefghijklmnopqrstuvwxyz";
    string s1="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char a,b;
    cin>>a;
    for(int i=0;i<s.size();i++)
    {
    	if(a==s[i])
    	{
    		b='a';
    		break;
		}
		if (a==s1[i])
		{
			b='A';
			break;
		}
		
	}
	cout<<b;
	return 0;
}