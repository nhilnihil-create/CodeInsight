#include<iostream>
using namespace std;
int main(){
	int H,W,i,j,ans1,ans2;
	for(;;){
		cin>>H>>W;
		if(H==0&&W==0){
			break;
		}
		for(i=1;i<=H;i++){
			ans1=i/2*2;
			for(j=1;j<=W;j++){
				ans2=j/2*2;
				if((ans1!=i)!=(ans2!=j)){
					cout<<".";
				}else{
					cout<<"#";
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}
		return 0;
	}