#include<iostream>
using namespace std;

int main(){
	int a=1,b=1,i,l;
	while((cin>>a>>b)&&(a!=0||b!=0)){
			for(i=1;i<=a;i++){
				if(i%2==1){
					if(b%2==0){
						for(l=1;l<=b/2;l++){
							cout<<"#.";
						}
						cout<<endl;
					}
					else{
						cout<<"#";
						for(l=1;l<=(b-1)/2;l++){
							cout<<".#";
						}
						cout<<endl;
					}
				}
				else{
					if(b%2==0){
						for(l=1;l<=b/2;l++){
							cout<<".#";
						}
						cout<<endl;
					}
					else{
						cout<<".";
						for(l=1;l<=(b-1)/2;l++){
							cout<<"#.";
						}
						cout<<endl;
					}
				}
			}
			cout<<endl;		
	}
}