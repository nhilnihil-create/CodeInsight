#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int H,W;
while(true){
cin>>H>>W;
	if(H==0&&W==0)break;
		for(int i=0;i<H;i++){
			if(W%2==0){
					if(i%2==0){
					for(int j=0;j<W/2;j++)cout<<"#.";
					}
					else{
					for(int j=0;j<W/2;j++)cout<<".#";
					}
				cout<<endl;	
			}
			
			else{
			if(i%2==0){
					for(int j=0;j<W/2;j++)cout<<"#.";
					cout<<"#";
					}
					else{
					for(int j=0;j<W/2;j++)cout<<".#";
					cout<<".";
					}
				cout<<endl;
			}
		
	}
	cout<<endl;
}
return 0;
}