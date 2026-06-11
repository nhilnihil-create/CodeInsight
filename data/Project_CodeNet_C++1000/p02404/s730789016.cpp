#include<iostream>
using namespace std;

int main(){
	int a=1,b=1,i,l;
	while((cin>>a>>b)&&(a!=0||b!=0)){
			for(l=1;l<=b;l++){
				cout<<"#";
			}
			cout <<endl;
			for(i=2;i<a;i++){
			cout<<"#";
				for(l=2;l<b;l++){
				cout<<".";
				}
			cout<<"#"<<endl;
			}
			for(l=1;l<=b;l++){
				cout<<"#";
			}
			cout <<endl;
		cout <<endl;		
	}
}