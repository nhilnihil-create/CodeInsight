#include<iostream>
using namespace std;

int main(){
  	char s[1005];
  	cin>>s;
  	int i;
  	for(i=0; s[i+1]!='\0';i++);
  	if(s[i]!='s')
      cout<<s<<"s";
  	else
      cout<<s<<"es";
	return 0;
}