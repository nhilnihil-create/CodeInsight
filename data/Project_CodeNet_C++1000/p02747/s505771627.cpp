#include<iostream>
using namespace std;
int main() {
	string str;
	cin>>str;
	char ch='h';
	int count = 0;
	for(int i = 0; i < str.length(); i++) {
		if(str[i]==ch) {
			count++;
			if(ch=='h')
				ch='i';
			else
				ch='h';		
		}
	}					
	if(str.length()/2+str.length()%2==count/2)
		cout<<"Yes";
	else
		cout<<"No";						
}