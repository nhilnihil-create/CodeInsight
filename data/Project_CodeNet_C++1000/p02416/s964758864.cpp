#include<iostream>
#include<cctype>
#include<string>
using namespace std;

int main()
{
	string string;
	int sum=0;
	int i=0;
	
	while(1){
		getline(cin, string);
		if(string[0]=='0')
			break;
		
		while(string[i]!='\0'){
			sum+=(string[i]-'0');
			i++;
		}
		
		cout << sum << endl;
		
		i=0;
		sum=0;
	}
	return 0;
}