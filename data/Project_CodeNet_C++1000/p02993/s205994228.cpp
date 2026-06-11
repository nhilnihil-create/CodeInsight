#include<iostream>
using namespace std;
int main(){
	string a;
	cin>>a;
	for(int i=0;i<a.size()-1;i++) if(a[i]==a[i+1]) return cout<<"Bad",0;
	cout<<"Good";
	return 0;
}
