#include<iostream>
using namespace std;
int main(){
  
	int H,W;
	cin>>H>>W;
	while(W!=0||H!=0){
		for(int i=1;i<=W;i++){
			cout<<"#";
				if(i==W){
					cout<<endl;
				}
		}
		for(int a=1;a<=H-2;a++){
			cout<<"#";
				for(int b=1;b<=W-2;b++){
					cout<<".";
				}
			cout<<"#"<<endl;
		}
		for(int d=1;d<=W;d++){
			cout<<"#";
				if(d==W){
					cout<<endl;
				}
		}
		cout<<endl;
		cin>>H>>W;
	}
				
	return 0;
}