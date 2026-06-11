#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{	
	string s;
	cin>>s;
	// if (s[0]='?'){s[0]='D';}
	for(int i=0;i<s.length();++i){
		if(s[i]=='?'){
			s[i]='D';
		}
	}
	cout<<s<<endl;
	return 0;
}