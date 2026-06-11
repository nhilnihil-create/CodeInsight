#include<bits/stdc++.h>
using namespace std;
typedef vector < vector < int > > vvi;
int n;
vvi calc(int n){
	if(n==1){
		vvi ret;
		ret.clear();
		return ret;
	}
	vvi A,B,R;
	R.clear();
	A=calc(n/2);
	B=calc((n+1)/2);
	R.resize(max(A.size(),B.size())+1);
	int i,j;
	for(i=0;i<(int)R.size();++i) R[i].resize(n);
	for(i=0;i<n/2;++i) R[0][i]=1;
	for(i=1;i<(int)R.size();++i){
		if((i-1)<(int)A.size()){
			for(j=0;j<n/2;++j) R[i][j]=A[i-1][j];
		}
		if((i-1)<(int)B.size()){
			for(j=n/2;j<n;++j) R[i][j]=B[i-1][j-n/2];
		}
	}
	return R;
}
int main(){
	int i,j,k;
	scanf("%d",&n);
	vvi col=calc(n);
	for(i=0;i<n-1;++i){
		for(j=i+1;j<n;++j){
			for(k=0;k<(int)col.size();++k){
				if(col[k][i]!=col[k][j]) break;
			}
			printf("%d ",k+1);
		}
		printf("\n");
	}
	return 0;
}