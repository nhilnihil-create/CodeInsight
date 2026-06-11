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
		for(int i=0;i<H;++i){
			for(int j=0;j<W;++j){
				cout<<"#";
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