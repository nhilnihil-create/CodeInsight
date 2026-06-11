/* last edited at 28.8.2015
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_D
*/

#include<iostream>
using namespace std;
int cnt=0;

void insertionSort(int A[], int N, int g){
	for(int i=g; i<N; i++){
		int v=A[i];
		int j=i-g;
		while(j>=0 && A[j]>v){
			A[j+g]=A[j];
			j=j-g;
			cnt++;				
		}
		A[j+g]=v;
	}
}

void shellSort(int A[], int N){
	int m=0;
	int G[N];
	for(int k=0; k<N; k++){
		if(k==0)G[0]=1;
		else G[k]=G[k-1]*3+1;
		//else G[k]=G[k-1]+3;
		m++;
		int q=G[k]*3+1;
		if(q>N) break;		
	}
	for(int k=m-1; k>=0; k--){
		insertionSort(A, N, G[k]);
	}
	cout << m << endl;
	for(int k=m-1; k>0; k--){
		cout << G[k] << " ";
	}
	cout << G[0] << endl; 
	cout << cnt << endl;
}

int main(){
	int N;
	cin >> N;
	int A[N];
	for(int i=0; i<N; i++){
		cin >> A[i];
	}
	shellSort(A, N);
	
	for(int i=0; i<N; i++){
		cout << A[i] << endl;
	}	
	
	return 0;
}