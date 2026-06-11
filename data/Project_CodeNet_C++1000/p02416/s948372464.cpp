#include <iostream>
#include <string>
using namespace std;
int main(){
	int a,b;
	string c;
	for(;;){
		a=0;
		cin>>c;
		b=c.size();
		if(c=="0"){
			return 0;
		}
		for(int i=0;i<b;i++){
			a=a+c[i]-'0';
		}
			cout<<a<<endl;
		}
	}

