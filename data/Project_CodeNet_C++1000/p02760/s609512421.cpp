#include <iostream>

using namespace std;

int main(){

	int a[3][3];
	for(int i=0;i<3;i++){
	
		for(int j=0;j<3;j++){
		
			cin>>a[i][j];
		}
	}
	int n;
	cin>>n;
	int b[n];
	for(int i=0;i<n;i++){
	
		cin>>b[i];
	}
     for(int x=0;x<n;x++){	

		for(int i=0;i<3;i++){
		
			for(int j=0;j<3;j++){
			
				if(a[i][j]==b[x]){
				
					a[i][j]=0;
				}
			}
		}
	}
		int ch=0;
		for(int i=0;i<3;i++){
		
			if(a[i][0]==a[i][1]&&a[i][1]==a[i][2]){

				cout<<"Yes";
				return 0;
			}
		}
		for(int i=0;i<3;i++){
		
			if(a[0][i]==a[1][i]&&a[1][i]==a[2][i]){

				cout<<"Yes";
				return 0;
			}
		}

		if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]){
		
			cout<<"Yes";
			return 0;
		}
		if(a[0][2]==a[1][1]&&a[1][1]==a[2][0]){
		
			cout<<"Yes";
			return 0;
		}

		cout<<"No";
		return 0;
}

