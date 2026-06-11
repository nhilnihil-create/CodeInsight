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
				if(j==1 || i==1 || j==H || i==W){
					cout<<"#";
				}else{
					cout<<".";
				}if(j==H && i==W){
					cout<<endl;
				}
			}
			cout<<endl;
		}
	}
	return 0;

}