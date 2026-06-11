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
		for(int i=0;i<a;i++){
			if((i+1)%2==1){
				for(int o=0;o<b;o++){
					if((o+1)%2==1)cout<<"#";
					else cout<<".";
				}
				cout<<endl;
			}
			else{
				for(int p=0;p<b;p++){
					if((p+1)%2==1)cout<<".";
					else cout<<"#";
				}
				cout<<endl;
			}
		}
		cout<<endl;
		cin>>a>>b;
	}
}

