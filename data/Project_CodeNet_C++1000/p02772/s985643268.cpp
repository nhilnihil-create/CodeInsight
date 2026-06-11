#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for(int i = 0; i < N; ++i) {
		if(A[i]%2==0){
			if(A[i]%3!=0&&A[i]%5!=0) {
				cout << "DENIED" << endl;
				return 0;
			}
		}
	}
	cout << "APPROVED" << endl;
}










