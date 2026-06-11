#include<iostream>
#include<string>
using namespace std;
int main(){
	int h=1000,w=1000;
	cin>>h>>w;
	while(w!=0&&h!=0){
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				if(i!=1&&i!=h&&j!=1&&j!=w){
					cout<<".";
				}
				else{
					cout<<"#";
				}
			}
			cout<<endl;
		}
		cout<<endl;	
		cin>>h>>w;	
	}	
}

