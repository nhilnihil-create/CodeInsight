#include <iostream>
using namespace std;

int main() {
	int m,n;cin>>m>>n;
	int a[m][n]={0};
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	int s=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
			s+=a[i][j];
		}
		cout<<s<<endl;
		s=0;
	}
	int b[n]={0};
	for(int j=0;j<n;j++){
		for(int i=0;i<m;i++){
			b[j]+=a[i][j];
		}
		cout<<b[j]<<" ";
	}
	for(int j=0;j<n-1;j++){
		b[n-1]+=b[j];
	}
	cout<<b[n-1]<<endl;
	return 0;
}