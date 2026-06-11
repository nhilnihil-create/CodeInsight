#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int> &A, int p, int r)
{
	int x = A[r];
	int i = p-1;
	for(int j = p; j < r; j++){
		if(A[j] <= x){
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i+1], A[r]);
	return i+1;
}

void OutputWithSpace(int C){
	cout << C << ' ';
}
void OutputWithEndl(int C){
	cout << C << endl;
}
void OutputWithSpaceAndBracket(int C){
	cout << '[' << C << "] ";
}
void OutputWithSpaceAndEndl(int C){
	cout << '[' << C << ']' << endl;
}

int main()
{
	int n;
	cin >> n;
	vector<int> A(n);
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	int q = Partition(A, 0, n-1);
	for(int i = 0; i < n; i++){
		if(i != q && i != n-1){
			OutputWithSpace(A[i]);
		}else if(i == q && i != n-1){
			OutputWithSpaceAndBracket(A[i]);
		}else if(i != q && i == n-1){
			OutputWithEndl(A[i]);
		}else{
			OutputWithSpaceAndEndl(A[i]);
		}
	}
	return 0;
}