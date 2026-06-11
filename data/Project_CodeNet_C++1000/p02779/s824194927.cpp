#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> A;
	for(int i=0;i<N;i++){
		int X;
		cin >> X;
		A.push_back(X);
	}
	sort(A.begin(), A.end());
	bool chk = true;
	for(int i=0;i<N-1;i++){
		if(A[i] == A[i+1]){
			chk = false;
			break;
		}
	}
	if(chk) cout << "YES" << endl;
	else cout << "NO" << endl;
}