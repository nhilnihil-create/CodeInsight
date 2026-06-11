#include <iostream>
using namespace std;
const int MAX_N = 100;
typedef long long lint;

int main() {
	int r,c;
	int a[MAX_N+1][MAX_N+1]={0};
	int sum=0;
	//in
	cin>>r>>c;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>a[i][j];
		}
	}
	//summer
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			a[i][c]+=a[i][j];
			a[r][j]+=a[i][j];
			sum+=a[i][j];
		}
	}
	a[r][c]=sum;
	//out
	for(int i=0;i<r+1;i++){
		for(int j=0;j<c+1;j++){
			if((j==c)){
				cout<<a[i][j];
			}else{cout<<a[i][j]<<" ";}
		}
		cout<<endl;
	}
	
	
	return 0;
}