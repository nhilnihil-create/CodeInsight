#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	while(a!=0&&b!=0){
		for(int i=0;i<b;i++){
			cout<<"#";
		}
		cout<<endl;
		for(int g=0;g<a-2;g++){
			cout<<"#";
			for(int h=0;h<b-2;h++){
				cout<<".";
			}
			cout<<"#"<<endl;
		}
		for(int j=0;j<b;j++){
			cout<<"#";
		}
		cout<<endl<<endl;
		cin>>a>>b;
	}
}

