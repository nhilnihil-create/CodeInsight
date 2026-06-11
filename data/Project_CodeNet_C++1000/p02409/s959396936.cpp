#include <iostream>
using namespace std;
main(){
	int n;cin>>n;
	int r[4][3][10]={0};
	for(int a,b,c,d,i=0;i<n;i++){
		cin>>a>>b>>c>>d;
		r[a-1][b-1][c-1]+=d;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<10;j++){
			cout<<" "<<r[0][i][j];
		}
		cout<<endl;
	}
	cout<<"####################"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<10;j++){
			cout<<" "<<r[1][i][j];
		}
		cout<<endl;
	}
	cout<<"####################"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<10;j++){
			cout<<" "<<r[2][i][j];
		}
		cout<<endl;
	}
	cout<<"####################"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<10;j++){
			cout<<" "<<r[3][i][j];
		}
		cout<<endl;
	}
	return 0;
}