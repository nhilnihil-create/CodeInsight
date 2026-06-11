#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int h,w,i,k;
	while(cin>>h>>w){
		if(h==0&&w==w){
			return 0;
			}
		for(k=0;k<h;k++){
			for(i=0;i<w;i++){
				if(k%2==0){
				if(i%2!=0){
				cout<<".";
				}
				else{
				cout<<"#";
				}
				}
				if(k%2!=0){
				if(i%2!=0){
					cout<<"#";
					}
				else{
					cout<<".";
					}
					}
				
			}cout<<endl;
			}cout<<endl;
			}
			return 0;
			}