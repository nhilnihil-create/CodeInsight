#include<iostream>
using namespace std;
int main(){
	string a;
	string b;
	int s=0;
	cin>>a>>b;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]==b[i])
			s++;
			
	}
	cout<<a.size()-s;
	return 0;
}