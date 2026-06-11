#include<iostream>
using namespace std;
int main(){
  
	int H,W;
	cin>>H>>W;
	while(H!=0||W!=0){
		for(int i=1;i<=H;i++){
			for(int a=1;a<=W-1;a++){
				cout<<"#";
			}
				cout<<"#"<<endl;
		}
		cout<<endl;
		cin>>H>>W;
	}
		
		
		
		
	return 0;
}