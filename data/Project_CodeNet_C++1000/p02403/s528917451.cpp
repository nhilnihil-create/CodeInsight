#include<iostream>
using namespace std;
int main(){

	int H,W,j,i;
	for(;;){
		int x=0;
		cin>>H>>W;
		if(H==0 && W==0){
			break;
		}
		for(j=1;j<=H;j++){
			for(i=1;i<=W;i++){
				cout<<"#";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;

}