#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n+1];
	int b[n+1];
	for(int i=1;i<=n;i++)
	b[i]=0;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		cout<<b[i]<<endl;
	}
}