#include<iostream>
#include<string>

using namespace std;

int main()
{
	string x;cin>>x;
	int length=x.length();
	
	if(x[length-1]=='s'){
		x.insert(length,"es");
	} else{
		x.insert(length,"s");	
	}
	
	cout<<x.c_str();
    return 0;
}