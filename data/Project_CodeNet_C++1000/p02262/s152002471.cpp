#include <iostream>
using namespace std;

int cnt=0;

int insertionSort(int A[],int n,int g){
	for(int i=g;i<=n-1;i++){
		int v=A[i];
		int j=i-g;
		while(j>=0&&A[j]>v){
			A[j+g]=A[j];
			j=j-g;
			cnt++;
		}
		A[j+g]=v;
	}
}

int main(){
	int i,n;
	int m=0;
	int G[13]={1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161};
	cin >> n;
	while(n>G[m] || (n==1&&m==0)) m++;
	int A[n];
	for(i=0;i<n;i++) cin >>A[i];
	for(i=m-1;i>=0;i--){
		insertionSort(A,n,G[i]);
	}
	cout << m << endl;
	for(i=m-1;i>=0;i--){
		if(i!=0) cout << G[i] << " ";
		else cout << G[i] << endl;
	}
	cout << cnt << endl;
	for(i=0;i<n;i++){
		cout << A[i] << endl;
	}
	return 0;
}