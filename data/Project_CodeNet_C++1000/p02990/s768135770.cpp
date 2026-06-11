//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e4 + 5;
const int  M  = 1e9+7;

int c[N][N];

int main(){
	
	for(int i=0;i<N;i++){
		c[i][0] = c[i][i] = 1;
		for(int j=1;j<i;j++){
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) %M;
		}
	}

	int n,m;
	cin>>n>>m;
	vector<int> ret(m+1);
	for(int k=1;k<=m;k++){
		if(n - m< k -1)break;
		ret[k] = (ll)c[m-1][k-1] * c[n-m+1][k] %M;
	}

	for(int i=1;i<=m;i++){
		cout<<ret[i]<<endl;
	}


	

	return 0;
}