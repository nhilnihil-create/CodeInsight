#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int tate,yoko,i,j;
	while(1){
	cin>>tate>>yoko;
	if(tate==0||yoko==0){
		break;
	}
		for(j=0;j<yoko;j++){
			cout<<"#";			
		}cout<<endl;
			for(j=0;j<tate-2;j++){
				cout<<"#";
				for(i=0;i<yoko-2;i++){
					cout<<".";
				}cout<<"#"<<endl;
			}for(j=0;j<yoko;j++){
			cout<<"#";			
		}cout<<endl;cout<<endl;
	}
  return 0;
}