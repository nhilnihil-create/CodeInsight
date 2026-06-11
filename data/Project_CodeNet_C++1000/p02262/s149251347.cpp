#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

struct TResult
{
	int m;
	vector<int> G;
	int cnt;
};

void insertionSort(vector<int> &A, int g, int &cnt)
{
	for(int i = g; i < A.size(); i++){
		int v = A[i];
		int j = i - g;
		while(j >= 0 && A[j] > v){
			A[j+g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j+g] = v;
	}
}

vector<int> FindShellSortNumber(int n)
{
	int g = 1;
	vector<int> G;
	while(g <= n){
		G.push_back(g);
		g = 3 * g + 1;
	}
	reverse(G.begin(), G.end());
	return G;
}

TResult shellSort(vector<int> &A)
{
	TResult Result;
	Result.cnt = 0;
	Result.G   = FindShellSortNumber(A.size());
	Result.m   = Result.G.size();
	for(int i = 0; i < Result.m; i++){
		insertionSort(A, Result.G[i], Result.cnt);
	}
	return Result;
}

vector<int> Input(int n)
{
	vector<int> A;
	A.resize(n);
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	return A;
}

void Output(TResult Result, vector<int> A)//????????´???Result??¨A??????????????????????????§&?????????
{
	cout << Result.m << endl;
	for(int i = 0; i < Result.G.size() - 1; i++){
		cout << Result.G[i] << ' ';
	}
	cout << Result.G[Result.G.size() - 1] << endl;
	cout << Result.cnt << endl;
	for(int i = 0; i < A.size(); i++){
		cout << A[i] << endl;
	}	
}

int main()
{
	int n;
	cin >> n;
	vector<int> A = Input(n);
	TResult Result = shellSort(A);
	Output(Result, A);
	return 0;
}