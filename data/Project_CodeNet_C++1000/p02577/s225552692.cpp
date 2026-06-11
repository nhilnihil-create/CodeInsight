#include<iostream>
#include<string>

using namespace std;

int main() 
{
	string x;
	cin>>x;
	
	int sum=0;
	for(int i=0;i<x.length();i++){
		sum+=x[i]-48;
	}
	
	if(sum%9==0){
		cout<<"Yes";
	} else{
		cout<<"No";
	}
	return 0;
}