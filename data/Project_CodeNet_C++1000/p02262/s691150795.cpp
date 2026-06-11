#include<bits/stdc++.h>
using namespace std;
int cnt  = 0;
int shell(int A[],int n,int g){
	int v,j;
	for(int i = g;i<n;i++){
		 v = A[i];
		 j = i-g;
		while(j>= 0 && A[j] >v ){
			A[j+g] = A[j];
			j = j-g;
			cnt++;
			A[j+g] = v;
		}
	}
	return 0;
}
int main(){
	int n,m = 0;
	cin>>n;
	int A[n];
	int g[13] = {1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161};
	for(int  i = 12;i>=0;i--){
		if(n/g[i] >=1){
			m = i;
			break;

		}
		
	}
	for(int i = 0;i<n;i++){
		cin>>A[i];
	}
	
	for(int i = 0;i<=m;i++){
		shell(A,n,g[m-i]);
	}
	cout<<m+1<<endl;
	for(int i = m;i>0;i--){
		cout<<g[i]<<" ";
	}
	cout<<g[0]<<endl;

	cout<<cnt<<endl;
	for(int i = 0;i<n;i++){
		cout<<A[i]<<endl;
	}
	return 0;
}
