
#include<iostream>
#include<string>
using namespace std;
int main(){
	for(;;){
		int H,W;
		cin>>H>>W;
		if(H==0&&W==0)break;
		else{
			for(int a=0;a<H;a++){
				if(a==0||a==H-1){
					for(int b=0;b<W;b++){
						cout<<"#";
					}
				}else{
					cout<<"#";
					for(int c=2;c<W;c++){
						cout<<".";
					}
					cout<<"#";
				}
				cout<<endl;
			}
			cout<<endl;
		}
	}
}

