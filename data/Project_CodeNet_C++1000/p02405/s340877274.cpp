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
				if((j/2*2!=j && i/2*2!=i)||(j/2*2==j && i/2*2==i)){
					cout<<"#";
				}else{
					cout<<".";
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;

}