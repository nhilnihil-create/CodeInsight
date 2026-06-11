#include <bits/stdc++.h>
#define pp pair<int,int>
#define fi first
#define si second
using namespace std;

int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<pp>v[n];
	for(int i=1,j=m+1;i<j;i++,j--){
		cout<<i<<' '<<j<<'\n';
	}
	for(int i=m+2,j=2*m+1;i<j;i++,j--){
		cout<<i<<' '<<j<<'\n';
	}
	return 0;
}