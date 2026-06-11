#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	char str[1000];
	char one_str[2] = {'0', '\0'};
	char *sp;
	int a, digit;
	cin>>str;
	a = atoi(str);
	while(a){
		digit=0;
		sp=str;
		while(1){
			if(*sp=='\0') break;
			one_str[0] = *sp;
			digit += atoi(one_str);
			sp++;
		}
		cout<<digit<<endl;
		cin>>str;
		a = atoi(str);
	}
	return 0;
}