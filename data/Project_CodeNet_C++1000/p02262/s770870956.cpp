#include<iostream>
#include<math.h>
using namespace std;

double log2(double x){
	return log(x)/log(2);
	
}

int out(int *A,int N){
	int i;
	for (i=0;i<=N-2;i++){
		cout << A[i] <<" ";
	}
	cout << A[N-1] <<endl;
	return 0;
}


int insertionSort(int *A,int n,int g){
	int cntnn=0,i,j,v;
	for (i=g;i<=n-1;i++){
		v=A[i];
		j=i-g;
		while (j>=0 && A[j]>v){
			A[j+g]=A[j];
			j=j-g;
			cntnn++;
		}
		A[j+g]=v;
	}
	return cntnn;
}

int shellSort(int *A,int n,int m, int *G){
	int cntn=0;
	int i,c;
	for (i=0;i<=m-1;i++){
		c=insertionSort(A,n,G[i]);
		cntn=cntn+c;
	}
	return cntn;
}

int main(){
	int n,cnt=0;
	cin >> n;
	int i;
	int A[n];
	for (i=0;i<=n-1;i++){
		cin >> A[i];
	}
	int m=floor(log2(n));
	if (n==1){
		m=1;
	}
	int G[m];
	for (i=m-1;i>=0;i--){
		G[i]=pow(2,m-i-1);
	}
	
	cnt=shellSort(A,n,m,G);
	
	cout << m <<endl;
	out(G,m);
	cout << cnt <<endl;
	for (i=0;i<=n-1;i++){
		cout << A[i] <<endl;
	}
	
	return 0;
}