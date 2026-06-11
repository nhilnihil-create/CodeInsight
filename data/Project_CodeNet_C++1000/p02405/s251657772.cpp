#include<iostream>

using namespace std;

int main(){
	int H,W,i,j,seki,sho;
		;
	for(;;){
		cin>>H>>W;
		if(H==0 && W==0){
			break;
		}
		for(i=0;i<H;i++){
			for(j=0;j<W;j++){
				seki=i+j;
				sho=seki/2*2;
				if(seki==sho){
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