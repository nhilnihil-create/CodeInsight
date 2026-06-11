#include<iostream>
using namespace std;

int main(){
	int a=1,b=1,i,l;
	while((cin>>a>>b)&&(a!=0||b!=0)){
		for(i=1;i<=a;i++){
			for(l=1;l<=b;l++){
				cout<<"#";
			}
			cout <<endl;
		}
		cout <<endl;
	}
}