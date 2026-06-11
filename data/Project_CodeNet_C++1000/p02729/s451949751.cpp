#include <iostream>
using namespace std;

int main() {
	int n,m,Sn=0,Sm=0,ans;
	cin>>n>>m;
	for(int i=0;i<n;i++)Sn=Sn+i;
	for(int j=0;j<m;j++)Sm=Sm+j;
	ans=Sn+Sm;
	cout<<ans;
	return 0;
}
