#include<iostream>
using namespace std;
int a[10];
int main(){
	int n=5;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			cout<<i<<endl;
			return 0;
		}
	}
}