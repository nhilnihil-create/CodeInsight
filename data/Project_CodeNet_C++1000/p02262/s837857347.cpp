#include<iostream>
#include<vector>
using namespace std;

void insertionSort(int n,int A[],int g);
void shellSort(int A[],int n);
void print(int A[],int n,vector<int> G,int m);

int count;
vector<int> G;

int main(){
	int n; cin>>n;
	int *A; A = new int[n];
	for(int i=0;i<n;i++) cin>>A[i];

	shellSort(A,n);

	delete [] A;
	cin.sync(); cin.get();
}

void insertionSort(int n,int A[],int g){
	for(int i=g;i<n;i++){
		int v = A[i];
		int j = i-g;
		while(j>=0 && A[j]>v){
			A[j+g] = A[j];
			j -= g;
			count++;
		}
		A[j+g] = v;
	}
}

void shellSort(int A[],int n){
	int m = 0;
	while(true){
		if(m==0)
			G.push_back(1);
		else
			G.push_back(3*G[m-1]+1);
		if(G[m]>n) break;
		m++;
	}

	for(int i=m-1;i>=0;i--)
		insertionSort(n,A,G[i]);

	print(A,n,G,m);
}

void print(int A[],int n,vector<int> G,int m){
	cout<<m<<endl;
	for(int i=m-1;i>=0;i--){
		cout<<G[i];
		if(i)
			cout<<" ";
		else
			cout<<endl;
	}
	cout<<count<<endl;
	for(int i=0;i<n;i++)
		cout<<A[i]<<endl;
}