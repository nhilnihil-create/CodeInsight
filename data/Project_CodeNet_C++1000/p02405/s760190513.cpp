#include<iostream>
using namespace std;
int main(){
  
	int W,H;
	cin>>H>>W;
	while(H!=0||W!=0){
		for(int a=1;a<=H;a++){
			if(a%2==0){
				for(int b=1;b<=W;b++){
					if(b%2==0){
						cout<<"#";
					}
					if(b%2==1){
						cout<<".";
					}
				}
			}
			if(a%2==1){
				for(int c=1;c<=W;c++){
					if(c%2==0){
						cout<<".";
					}
					if(c%2==1){
						cout<<"#";
					}
				}
			}
		cout<<endl;
		}
		cout<<endl;
		cin>>H>>W;
	}
				
	return 0;
}