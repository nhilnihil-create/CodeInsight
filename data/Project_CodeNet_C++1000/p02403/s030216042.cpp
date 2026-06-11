#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
 int i,tate,yoko;
while(cin>>tate>>yoko){
		if(tate==0&&yoko==0){
			break;
		}
	for(int j=0;j<tate;j++){
		for(i=0;i<yoko;i++){
			cout<<"#";
		}cout<<endl;
	}cout<<endl;
}	
return 0;
}