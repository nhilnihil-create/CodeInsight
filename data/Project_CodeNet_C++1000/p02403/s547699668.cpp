#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<strings.h>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	while(a!=0&&b!=0){
		for(int i=0;i<a;i++){
			for(int k=0;k<b;k++){
				cout<<"#";
			}
			cout<<endl;
		}
		cout<<endl;
		cin>>a>>b;
	}
}

