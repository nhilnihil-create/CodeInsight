#include<iostream>
using namespace std;
int main(){
	int a, b;
	cin>>a;
	if(a%1000!=0)
	b=a/1000+1;
	else
	b=a/1000;
	
	b=b*1000;
	cout<<(b-a);
	return 0;
} 