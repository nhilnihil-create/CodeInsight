#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <string>

using namespace std;
		
int main(void){
	string str,search;
	cin>>str>>search;
	while(str.size()<=100){
		str = str + str;
	}
	if(str.find(search)==-1)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
	
	return 0;
}