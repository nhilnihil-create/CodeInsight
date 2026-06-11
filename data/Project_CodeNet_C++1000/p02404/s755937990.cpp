#include<iostream>

using namespace std;

int main(){

	int H,W;
	bool flag= true;
	cin>>H>>W;
	if(H==0&&W==0){
			flag = false;
		}
	while(flag==true){
		for(int i=1;i<=H;i++){
			for(int j=1;j<=W;j++){
				cout<<"#";
					if(1<i&&i<H&&0<j&&j<W){
						for(int k=1;k<W-1;k++){
							cout<<".";
							j=W-1;
						}
					}
			}
		cout<<endl;
		
		}
		cin>>H>>W;
		if(H==0&&W==0){
			flag = false;
		}
		cout<<endl;
	}
	return 0;
}