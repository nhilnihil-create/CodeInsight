#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
	int H,W,i=0,j=0,k=0;
	while(cin>>H>>W){
		if(H==0&&W==0) break;
		for(i=1;i<=H;i++){
			for(j=1;j<W;j++){
				if(i==1||i==H)cout<<"#";
				else {
					cout<<"#";
					for(k=0;k<W-2;k++){
						cout<<".";
						}
					break;
					}
			}
			cout<<"#"<<endl;
		}
	cout<<endl;
	}
	return 0;
}