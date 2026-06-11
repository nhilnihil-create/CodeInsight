#include<bits/stdc++.h>
using namespace std;

int N, e = 1;
void dfs(vector<char> &A) {
	if(A.size() == N) {
		for (int i = 0; i < N; i++) cout << A[i];
		cout << endl;
		return;
	}

	for (char v = 'a'; v <= *max_element(A.begin(), A.end())+1; v++)
	{
		A.push_back(v);
		dfs(A);
		A.pop_back();
	}
	
}
int main() {
	cin >> N;
	vector<char> A;
	A.push_back('a');
	dfs(A);
	return 0;
}
