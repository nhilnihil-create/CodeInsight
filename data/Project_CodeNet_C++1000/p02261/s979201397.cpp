#include<iostream>
#include<vector>
using namespace std;

struct card{
	int  number;
	char mark;
};

void BubbleSort(vector<card> &A)
{
	bool flag = true;
	while(flag){
		flag = false;
		for(int j = A.size() - 1; j >= 1; j--){
			if(A[j].number < A[j-1].number){
				swap(A[j], A[j-1]);
				flag = true;
			}
		}
	}
}

void SelectionSort(vector<card> &A)
{
	for(int i = 0; i < A.size(); i++){
		int minj = i;
		for(int j = i; j < A.size(); j++){
			if(A[j].number < A[minj].number){
				minj = j;
			}
		}
		if(minj != i){
			swap(A[i], A[minj]);
		}
	}
}

void Output(vector<card> A)
{
	int n = A.size() - 1;
	for(int i = 0; i < n; i++){
		cout << A[i].mark << A[i].number << ' ';
	}
	cout << A[n].mark << A[n].number << endl;
}

vector<card> Input()
{
	int N;
	cin >> N;
	vector<card> A;
	A.resize(N);
	for(int i = 0; i < N; i++){
		cin >> A[i].mark >> A[i].number;
	}
	return A;
}

bool Judge(vector<card> A, vector<card> B){
	for(int i = 0; i < A.size(); i++){
		if(A[i].mark != B[i].mark){
			return false;
		}
	}
	return true;
}

int main()
{
	vector<card> A = Input();
	vector<card> B = A;
	
	BubbleSort(A);
	Output(A);
	cout << "Stable" << endl;
	SelectionSort(B);
	Output(B);
	if(Judge(A, B)){
		cout << "Stable" << endl;
	}else{
		cout << "Not stable" <<endl;
	}
	return 0;
}