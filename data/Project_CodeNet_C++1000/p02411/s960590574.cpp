#include<iostream>
using namespace std;
int main(){
	
	int m,f,r,mf;
	cin>>m>>f>>r;
	while(m!=-1||f!=-1||r!=-1){
		mf=m+f;
		if(m==-1||f==-1){
			cout<<"F"<<endl;
		}
		if(m!=-1&&f!=-1){
			if(mf>=80){
				cout<<"A"<<endl;
			}
			if(mf<80&&mf>=65){
				cout<<"B"<<endl;
			}
			if(mf<65&&mf>=50){
				cout<<"C"<<endl;
			}
			if(mf<50&&mf>=30){
				if(r>=50){
					cout<<"C"<<endl;
				}
				else{
					cout<<"D"<<endl;
				}
			}
			if(mf<30){
				cout<<"F"<<endl;
			}
		}
			cin>>m>>f>>r;
	}	
	return 0;
}