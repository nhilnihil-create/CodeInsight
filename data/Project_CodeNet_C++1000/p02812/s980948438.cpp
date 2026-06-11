#include<iostream>
using namespace std;
int main(){
	string a;
	int n;
	cin>>n>>a;
	int k=0;
	for(int i=0;i<n;i++)
		if(a[i]=='A'&&a[i+1]=='B'&&a[i+2]=='C')
			k++;
	cout<<k<<"\n";
	return 0;
}