// ALDS1_6_B
#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int partition(vector<int> &A, int p, int r){
	int x = A[r], i = p-1;

	for(int j=p;j<r;j++){
		if(A[j] <= x){
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i+1], A[r]);

	return i+1;
}

int main(){
	int n, num;
	vector<int> A;

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		A.push_back(num);
	}

	num = partition(A, 0, n-1);
	for(int i=0;i<n;i++){
		if(i != 0)
			cout<<" ";

		if(i != num)
			cout<<A[i];
		else
			cout<<"["<<A[i]<<"]";
	}
	cout<<endl;

	return 0;
}