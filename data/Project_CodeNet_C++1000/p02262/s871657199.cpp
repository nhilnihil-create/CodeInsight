// ALDS1_2_D
#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &A, int &cnt, int g){
	for(int i=g;i<A.size();i++){
		int v = A[i], j = i-g;

		while((j >= 0) && (A[j] > v)){
			A[j+g] = A[j];
			j -= g;
			cnt++;
		}
		A[j+g] = v;
	}
}

void shellSort(vector<int> &A){
	int m, cnt = 0;
	vector<int> G;

	G.push_back(1);
	while(G[G.size()-1] <= A.size())
		G.push_back(3*G[G.size()-1]+1);
	m = G.size();

	for(int i=m-2;i>=0;i--)
		insertionSort(A, cnt, G[i]);

	cout<<m-1<<endl;
	for(int i=m-2;i>=0;i--){
		if(i != m-2)
			cout<<" ";
		cout<<G[i];
	}
	cout<<endl<<cnt<<endl;
}

int main(){
	int n, num;
	vector<int> A;

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		A.push_back(num);
	}

	shellSort(A);

	for(int i=0;i<n;i++)
		cout<<A[i]<<endl;

	return 0;
}