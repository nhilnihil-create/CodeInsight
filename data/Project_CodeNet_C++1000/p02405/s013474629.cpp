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
				if(i%2==1){
					if(j%2==1)cout<<"#";
					else cout<<".";
					}
				else{
					if(j%2==1)cout<<".";
					else cout<<"#";
				}
			}
			if (W%2==0){
				if(i%2==1) cout<<"."<<endl;
				else cout<<"#"<<endl;
				}
			else{
				if(i%2==1) cout<<"#"<<endl;
				else cout<<"."<<endl;
			}
		}
	cout<<endl;
	}
	return 0;
}