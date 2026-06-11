#include<iostream>
using namespace std;
int main(){
	int H,W,i,j,sum=0,ans=0;
	for(;;){
		cin>>H>>W;
		if(H==0 && W==0)break;
		for(i=1;i<=H;i++){
			for(j=1;j<=W;j++){
				sum=j+i;
				ans=sum/2*2;

			if(ans==sum){
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