#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long mul=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			mul=mul+(a[i]*a[j]);
		}
	}
	cout<<mul<<endl;
}