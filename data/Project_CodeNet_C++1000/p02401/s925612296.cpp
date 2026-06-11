#include<iostream>
using namespace std;
int main(){
	int a,b;
	char c;
	while(cin>>a>>c>>b){
		if(c=='?')	break;
		if(c=='+'){
			cout<<a+b<<endl;
			continue;
		}
		else if(c=='-'){
			cout<<a-b<<endl;
			continue;
		}
		else if(c=='*'){
			cout<<a*b<<endl;
			continue;
		}
		else if(c=='/'){
			cout<<a/b<<endl;
			continue;
		}
	}
	return 0;
}